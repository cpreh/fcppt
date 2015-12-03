//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MOD_ASSIGN_HPP_INCLUDED
#define FCPPT_MATH_MOD_ASSIGN_HPP_INCLUDED

#include <fcppt/math/detail/mod_assign.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Assigns the result of @a l mod @a r to l

\ingroup fcpptmath

It uses std::fmod for floating point types. Otherwise %= is used. The
behaviour will, of course, be undefined if r is 0.
*/
template<
	typename T
>
void
mod_assign(
	T& l,
	T const &r
)
{
	detail::mod_assign(
		l,
		r
	);
}

}
}

#endif
