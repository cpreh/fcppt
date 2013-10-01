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
	void
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

	bool const steep =
		fcppt::math::diff(
			y1,
			y0
		)
		>
		fcppt::math::diff(
			x1,
			x0
		);

	if(
		steep
	)
	{
		std::swap(
			x0,
			y0
		);

		std::swap(
			x1,
			y1
		);
	}

	if(
		x0 > x1
	)
	{
		std::swap(
			x0,
			x1
		);

		std::swap(
			y0,
			y1
		);
	}

	T const dx(
		x1 - x0
	);

	T const dy(
		fcppt::math::diff(
			y1,
			y0
		)
	);

	T diff(
		fcppt::literal<
			T
		>(
			2
		)
		* dy
		- dx
	);

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

	_callback(
		vector_type(
			x0,
			y0
		)
	);

	T y(
		y0
	);

	T const two(
		fcppt::literal<
			T
		>(
			2
		)
	);

	for(
		T x(
			x0
			+
			fcppt::literal<
				T
			>(
				1
			)
		);
		x <= x1;
		++x
	)
	{
		bool const inc_y(
			diff
			>
			fcppt::literal<
				T
			>(
				0
			)
		);

		if(
			inc_y
		)
			++y;

		if(
			!_callback(
				steep
				?
					vector_type(
						y,
						x
					)
				:
					vector_type(
						x,
						y
					)
			)
		)
			return;

		diff +=
			inc_y
			?
				two * dy
				-
				two * dx
			:
				two * dy;
	}
}

}
}

#endif
