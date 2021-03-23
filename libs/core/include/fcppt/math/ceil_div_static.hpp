//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_CEIL_DIV_STATIC_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_STATIC_HPP_INCLUDED

#include <fcppt/math/detail/ceil_div_static.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Calculates a division of integral contants rounded towards infinity.

\ingroup fcpptmath

Calculates <code>Dividend / Divisor</code> rounded towards infinity. For
example, <code>5 / 3</code> would result in <code>2</code>.
The result type is a <code>std::integral_constant<Type,V></code>,
where <code>V</code> is the calculated value.

\tparam Type Must be an unsigned integral type

\tparam Dividend The dividend

\tparam Divisor The divisor
*/
template <typename Type, Type Dividend, Type Divisor>
using ceil_div_static =
    typename fcppt::math::detail::ceil_div_static<Type, Dividend, Divisor>::type;

}
}

#endif
