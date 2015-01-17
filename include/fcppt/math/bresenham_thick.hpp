//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BRESENHAM_THICK_HPP_INCLUDED
#define FCPPT_MATH_BRESENHAM_THICK_HPP_INCLUDED

#include <fcppt/math/detail/bresenham_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

template<
	typename T,
	typename N,
	typename S1,
	typename S2,
	typename Callback
>
inline
typename
std::enable_if<
	N::value
	==
	2,
	bool
>::type
bresenham_thick(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const _start,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const _end,
	Callback const &_callback
)
{
	return
		fcppt::math::detail::bresenham_impl<
			true
		>(
			_start,
			_end,
			_callback
		);
}

}
}

#endif
