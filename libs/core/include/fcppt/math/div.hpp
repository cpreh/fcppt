//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIV_HPP_INCLUDED
#define FCPPT_MATH_DIV_HPP_INCLUDED

#include <fcppt/math/is_zero.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates dividend / divisor.

\ingroup fcpptmath

In case divisor is 0, nothing is returned.

\tparam T Any type that works with \link fcppt::math::is_zero\endlink.
*/
template<
	typename T
>
fcppt::optional::object<
	T
>
div(
	T const &_dividend,
	T const &_divisor
)
{
	return
		fcppt::optional::make_if(
			!fcppt::math::is_zero(
				_divisor
			),
			[
				_dividend,
				_divisor
			]{
				return
					_dividend
					/
					_divisor;
			}
		);
}

}
}

#endif
