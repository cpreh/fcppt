//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_PARTITION_HPP_INCLUDED
#define FCPPT_VARIANT_PARTITION_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/mpl/list/index_of.hpp>
#include <fcppt/tuple/element.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/init.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/partition_result.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief Partitions a container of variants into multiple containers.
\ingroup fcpptvariant

\tparam Container A container of #fcppt::variant::object.
*/
template <typename Container>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
[[nodiscard]] fcppt::variant::partition_result<Container> partition(Container &&_container)
{
  using variant = fcppt::type_traits::value_type<Container>;
  using result_type = fcppt::variant::partition_result<Container>;

  result_type result{fcppt::tuple::init<result_type>(
      []<std::size_t Index>(std::integral_constant<std::size_t, Index>)
      { return fcppt::tuple::element<Index, result_type>{}; })};

  for (auto &element : _container)
  {
    fcppt::variant::apply(
        [&result](auto &inner)
        {
          using index = fcppt::mpl::list::
              index_of<fcppt::variant::types_of<variant>, std::remove_cvref_t<decltype(inner)>>;
          fcppt::tuple::get<index::value>(result).push_back(
              fcppt::move_if_rvalue<decltype(element)>(inner));
        },
        element);
  }

  return result;
}

}

#endif
