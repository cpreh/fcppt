//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_STEP_HPP_INCLUDED
#define FCPPT_MATH_STEP_HPP_INCLUDED

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
			static_cast<T>(
				1
			)
		:
			static_cast<T>(
				0
			);
}
}
}

#endif
