//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/index_of_if.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/record/detail/make_tag_tuple.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/invoke.hpp>
#include <fcppt/tuple/map.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record::detail
{
template <typename Result, typename TagTuple, typename... Args>
Result init_ctor(Args &&..._args)
{
  fcppt::tuple::object<std::remove_cvref_t<Args>...> arguments{std::forward<Args>(_args)...};

  using args_list = fcppt::mpl::list::object<std::remove_cvref_t<Args>...>;

  return fcppt::tuple::invoke(
      [](auto &&..._args_inner) -> Result {
        return Result{std::forward<decltype(_args_inner)>(_args_inner)...};
      },
      fcppt::tuple::map(
          fcppt::record::detail::make_tag_tuple<TagTuple>(),
          [&arguments]<typename Label, typename Type>(fcppt::tag<fcppt::record::element<Label, Type>>) {
            using index_type = fcppt::mpl::list::index_of_if<
                args_list,
                fcppt::mpl::bind<
                    fcppt::mpl::lambda<fcppt::record::detail::label_is_same>,
                    fcppt::mpl::constant<Label>,
                    fcppt::mpl::arg<1>>>;

            return std::move(fcppt::tuple::get<index_type::value>(arguments).value());
          }));
}

}

#endif
