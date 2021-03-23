//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_CEIL_DIV_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Calculates dividend / divisor rounded towards infinity.

\ingroup fcpptmath

In case divisor is 0, nothing is returned. Otherwise, returns (dividend /
divisor) if dividend can be divided by divisor, and (dividend / divisor) + 1 if
dividend can not be divided by divisor.

\tparam T An unsigned type.
*/
template <typename T>
fcppt::optional::object<T> ceil_div(T const &_dividend, T const &_divisor)
{
  static_assert(std::is_unsigned<T>::value, "ceil_div can only be used on unsigned types");

  T const zero{fcppt::literal<T>(0)};

  return fcppt::optional::make_if(_divisor != zero, [_dividend, _divisor] {
    return _dividend / _divisor +
           (_dividend % _divisor ? fcppt::literal<T>(1) : fcppt::literal<T>(0));
  });
}

}
}

#endif
