//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TUPLE_FROM_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_FROM_ARRAY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/tuple/from_array_result.hpp>
#include <fcppt/container/tuple/init.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace tuple
{
/**
\brief Converts a std::array to a std::tuple.

\ingroup fcpptcontainertuple

\tparam Array Must be a std::array.
*/
template <typename Array>
fcppt::container::tuple::from_array_result<Array> from_array(Array &&_source)
{
  static_assert(
      fcppt::type_traits::is_std_array<fcppt::type_traits::remove_cv_ref_t<Array>>::value);

  return fcppt::container::tuple::init<fcppt::container::tuple::from_array_result<Array>>(
      [&_source](auto const _index) {
        return fcppt::move_if_rvalue<Array>(std::get<_index()>(_source));
      });
}

}
}
}

#endif
