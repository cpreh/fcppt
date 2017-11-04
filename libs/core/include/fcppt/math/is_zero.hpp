//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_ZERO_HPP_INCLUDED
#define FCPPT_MATH_IS_ZERO_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/literal.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Compares a value against zero.

\ingroup fcpptmath

Uses \link fcppt::literal\endlink to create a zero constant
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
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-equal)
	return
		_value
		==
		fcppt::literal<
			T
		>(
			0
		);
FCPPT_PP_POP_WARNING
}

}
}

#endif
