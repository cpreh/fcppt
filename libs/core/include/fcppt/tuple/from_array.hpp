//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_FROM_ARRAY_HPP_INCLUDED
#define FCPPT_TUPLE_FROM_ARRAY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/get.hpp>
#include <fcppt/array/is_object.hpp>
#include <fcppt/tuple/from_array_result.hpp>
#include <fcppt/tuple/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Converts an fcppt::array::object to an fcppt::tuple::object.

\ingroup fcppttuple
*/
template <
    typename Array,
    typename = std::enable_if_t<
        fcppt::array::is_object<std::remove_cvref_t<Array>>::value>>
[[nodiscard]] fcppt::tuple::from_array_result<std::remove_cvref_t<Array>>
from_array(Array &&_source)
{
  return fcppt::tuple::init<
      fcppt::tuple::from_array_result<std::remove_cvref_t<Array>>>(
      [&_source](auto const _index) {
        return fcppt::move_if_rvalue<Array>(fcppt::array::get<_index()>(_source));
      });
}
}

#endif
