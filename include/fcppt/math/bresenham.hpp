//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BRESENHAM_HPP_INCLUDED
#define FCPPT_MATH_BRESENHAM_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
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
typename
std::enable_if<
	N::value
	==
	2,
	bool
>::type
bresenham(
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
	static_assert(
		std::is_signed<
			T
		>::value,
		"bresenham currently only works on signed types"
	);

	T x0(
		_start.x()
	);

	T y0(
		_start.y()
	);

	T x1(
		_end.x()
	);

	T y1(
		_end.y()
	);

	T const two(
		fcppt::literal<
			T
		>(
			2
		)
	);

	T const one(
		fcppt::literal<
			T
		>(
			1
		)
	);

	T const dx(fcppt::math::diff(
		x1,
		x0
	));

	T const dy(fcppt::math::diff(
		y1,
		y0
	));

	T sx(
		x0 < x1
		?
		one
		:
		-one);

	T sy(
		y0 < y1
		?
		one
		:
		-one);

	T err(
		dx
		-
		dy);

	typedef
	fcppt::math::vector::object<
		T,
		N,
		fcppt::math::static_storage<
			T,
			N
		>
	>
	vector_type;

	auto const
	plot =
	[
		&_callback
	](
		T const &x,
		T const &y
	){
			return _callback(
				vector_type(
					x,
					y
				)
			);
	};

	while(
		true
	)
	{
		if(
			!plot(x0,y0)
		)
			return false;

		if(
			x0 == x1
			&&
			y0 == y1
		)
			break;

		T err2(
			two * err);

		if(
			err2
			>
			-dy
		)
		{
			err -=
				dy;
			x0 += sx;

#if 0
			plot(
				x0 - sx,
				y0);
#endif
		}

		if(
			x0 == x1
			&&
			y0 == y1
		)
		{
			if(
				!plot(x0,y0)
			)
				return false;
			break;
		}

		if(
			err2
			<
			dx
		)
		{
			err +=
				dx;
			y0 += sy;
#if 0
			plot(
				x0,
				y0-sy);
#endif
		}
	}

	return true;
}

}
}

#endif
