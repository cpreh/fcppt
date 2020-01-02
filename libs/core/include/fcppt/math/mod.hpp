//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MOD_HPP_INCLUDED
#define FCPPT_MATH_MOD_HPP_INCLUDED

#include <fcppt/math/is_zero.hpp>
#include <fcppt/math/detail/mod.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Wraps the integral modulo operator and the floating point modulo functions.

It uses std::%fmod for floating point types. Otherwise % is used.
Returns nothing if \a _divisor is zero.

\ingroup fcpptmath

\tparam T A floating-point type or an unsigned type.
*/
template<
	typename T
>
inline
fcppt::optional::object<
	T
>
mod(
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
					fcppt::math::detail::mod(
						_dividend,
						_divisor
					);
			}
		);
}

}
}

#endif
