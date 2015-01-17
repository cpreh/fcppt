//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_BRESENHAM_THICK_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_BRESENHAM_THICK_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	bool Thick,
	typename Callback,
	typename T
>
inline
typename
std::enable_if<
	Thick,
	bool
>::type
bresenham_thick(
	Callback const &_callback,
	T const _x,
	T const _y
)
{
	return
		_callback(
			_x,
			_y
		);
}

template<
	bool Thick,
	typename Callback,
	typename T
>
inline
typename
std::enable_if<
	!Thick,
	bool
>::type
bresenham_thick(
	Callback const &,
	T,
	T
)
{
	return
		true;
}

}
}
}

#endif
