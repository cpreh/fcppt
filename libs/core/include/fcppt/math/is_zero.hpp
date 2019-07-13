//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_ZERO_HPP_INCLUDED
#define FCPPT_MATH_IS_ZERO_HPP_INCLUDED

#include <fcppt/math/is_zero_impl_fwd.hpp>
#include <fcppt/math/is_zero_literal.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Compares a value against zero.

\ingroup fcpptmath

Uses #fcppt::literal to create a zero constant
and uses <code>operator==</code> for comparison.

This function is special because it also allows comparison of floating-point
values against zero, which would otherwise trigger a warning.
*/
template<
	typename T
>
inline
bool
is_zero(
	T const &_value
)
{
	return
		fcppt::math::is_zero_impl<
			T
		>::get(
			_value
		);
}

}
}

#endif
