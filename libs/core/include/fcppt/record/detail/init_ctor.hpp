//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/metal/index_of_if.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/record/detail/make_tag_tuple.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/invoke.hpp>
#include <fcppt/tuple/map.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
namespace detail
{
template <typename Result, typename TagTuple, typename... Args>
Result init_ctor(Args &&..._args)
{
  fcppt::tuple::object<fcppt::type_traits::remove_cv_ref_t<Args>...> arguments(std::move(_args)...);

  using args_list = ::metal::list<fcppt::type_traits::remove_cv_ref_t<Args>...>;

  return fcppt::tuple::invoke(
      [](auto &&..._args_inner) -> Result {
        return Result{std::forward<decltype(_args_inner)>(_args_inner)...};
      },
      fcppt::tuple::map(
          fcppt::record::detail::make_tag_tuple<TagTuple>(),
          [&arguments](auto const _fcppt_element) {
            FCPPT_USE(_fcppt_element);

            using index_type = fcppt::metal::index_of_if<
                args_list,
                ::metal::bind<
                    ::metal::trait<fcppt::record::detail::label_is_same>,
                    ::metal::always<
                        fcppt::record::element_to_label<fcppt::tag_type<decltype(_fcppt_element)>>>,
                    ::metal::_1>>;

            return std::move(fcppt::tuple::get<index_type::value>(arguments).value());
          }));
}

}
}
}

#endif
