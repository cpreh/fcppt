//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MOD_HPP_INCLUDED
#define FCPPT_MATH_MOD_HPP_INCLUDED

#include <fcppt/math/detail/mod.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Wraps the integral modulo operator and the floating point modulo functions
\ingroup fcpptmath
\tparam T Any numeric type

It uses std::%fmod for floating point types. Otherwise % is used.
The behaviour will, of course, be undefined if r is 0.
*/
template<
	typename T
>
T
mod(
	T const &a,
	T const &b
)
{
	return
		detail::mod(
			a,
			b
		);
}

}
}

#endif
