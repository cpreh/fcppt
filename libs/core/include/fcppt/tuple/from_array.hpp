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
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Converts an fcppt::array::object to an fcppt::tuple::object.

\ingroup fcppttuple
*/
template <typename Array>
[[nodiscard]] fcppt::tuple::from_array_result<std::remove_cvref_t<Array>>
from_array(Array &&_source) // NOLINT(cppcoreguidelines-missing-std-forward)
  requires(fcppt::array::is_object<std::remove_cvref_t<Array>>::value)
{
  return fcppt::tuple::init<fcppt::tuple::from_array_result<std::remove_cvref_t<Array>>>(
      [&_source]<std::size_t Index>(std::integral_constant<std::size_t, Index>)
      { return fcppt::move_if_rvalue<Array>(fcppt::array::get<Index>(_source)); });
}
}

#endif
