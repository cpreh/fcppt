//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_BRESENHAM_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_BRESENHAM_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/detail/bresenham_thick.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
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
bresenham_impl(
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

	T const dx(
		fcppt::math::diff(
			x1,
			x0
		)
	);

	T const dy(
		fcppt::math::diff(
			y1,
			y0
		)
	);

	T const sx(
		x0 < x1
		?
		one
		:
		-one);

	T const sy(
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
	fcppt::math::vector::static_<
		T,
		N::value
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

			if(
				!fcppt::math::detail::bresenham_thick<
					Thick
				>(
					plot,
					x0 - sx,
					y0
				)
			)
				return false;
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

			if(
				!fcppt::math::detail::bresenham_thick<
					Thick
				>(
					plot,
					x0,
					y0 - sy
				)
			)
				return false;
		}
	}

	return true;
}

}
}
}

#endif
