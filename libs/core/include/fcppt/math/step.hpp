//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_STEP_HPP_INCLUDED
#define FCPPT_MATH_STEP_HPP_INCLUDED

#include <fcppt/literal.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Implements a step function returning either zero or one
\ingroup fcpptmath
\tparam T A type with an operator>= which is convertible from 1 and 0

Returns 1 if _value >= _vmin, else 0.
*/
template<
	typename T
>
T
step(
	T const &_value,
	T const &_vmin
)
{
	return
		_value >= _vmin
		?
			fcppt::literal<
				T
			>(
				1
			)
		:
			fcppt::literal<
				T
			>(
				0
			);
}

}
}

#endif
