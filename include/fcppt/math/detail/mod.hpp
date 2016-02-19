//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MOD_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MOD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
typename std::enable_if<
	std::is_floating_point<
		T
	>::value,
	T
>::type
mod(
	T const &a,
	T const &b
)
{
	return std::fmod(a, b);
}

template<
	typename T
>
typename std::enable_if<
	std::is_unsigned<
		T
	>::value,
	T
>::type
mod(
	T const &a,
	T const &b
)
{
	return a % b;
}

}
}
}


#endif
