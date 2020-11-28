//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_NEXT_POWER_OF_2_HPP_INCLUDED
#define FCPPT_MATH_NEXT_POWER_OF_2_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Calculates the next power of 2 for an unsigned value.

\ingroup fcpptmath

If _value is a power of two, then _value is returned.
Otherwise, the least power of two that is greater than _value is returned.

\tparam T An unsigned type
*/
template <typename T>
T next_power_of_2(T const _value)
{
  static_assert(std::is_unsigned_v<T>, "next_power_of_2 can only be used on unsigned types");

  if (_value == fcppt::literal<T>(0))
  {
    return fcppt::literal<T>(1);
  }

  T const two(fcppt::literal<T>(2));

  if (fcppt::math::is_power_of_2(_value))
  {
    return _value;
  }

  T counter(_value);

  T ret(fcppt::literal<T>(1));

  while ((counter /= two) != fcppt::literal<T>(0))
  {
    ret *= two;
  }

  return ret * two;
}

}
}

#endif
