//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_CEIL_DIV_SIGNED_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_SIGNED_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/math/ceil_div.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math
{
/**
\brief Calculates dividend / divisor rounded towards infinity.

\ingroup fcpptmath

The same as #fcppt::math::ceil_div, except in case where dividend
is negative, dividend / divisor is returned.

\tparam T A signed type
*/
template <typename T>
fcppt::optional::object<T> ceil_div_signed(T const &_dividend, T const &_divisor)
{
  static_assert(std::is_signed<T>::value, "ceil_div_signed can only be used on signed types");

  T const zero{fcppt::literal<T>(0)};

  return (_dividend < zero)
             ? fcppt::optional::make_if(
                   _divisor != zero, [_dividend, _divisor] { return _dividend / _divisor; })
             : fcppt::optional::map(
                   fcppt::math::ceil_div(
                       fcppt::cast::to_unsigned(_dividend), fcppt::cast::to_unsigned(_divisor)),
                   [](std::make_unsigned_t<T> const _result) {
                     return fcppt::cast::to_signed(_result);
                   });
}

}

#endif
