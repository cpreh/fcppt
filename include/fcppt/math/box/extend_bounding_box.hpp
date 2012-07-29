//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/contains_point.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/preprocessor/const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{
/**
\brief Extend a box to fit a point in it
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

The result will either be the same box (if the point is contained in the box)
or a box that's just big enough to hold the given point.
*/
template<typename T,fcppt::math::size_type N>
fcppt::math::box::object<T,N> const
extend_bounding_box(
	fcppt::math::box::object<T,N> b,
	typename fcppt::math::box::object<T,N>::vector const &p)
{
	if (fcppt::math::box::contains_point(
		b,
		p))
		return b;

	for (fcppt::math::size_type i = 0; i < N; ++i)
	{
		if (p[i] < b.pos()[i])
		{
			b.size(
				i,
				b.size()[i] + (b.pos()[i] - p[i]));

			b.pos(
				i,
				p[i]);

			continue;
		}

		T const end =
			static_cast<T>(
				b.pos()[i] + b.size()[i]);

		if (p[i] > end)
			b.size(
				i,
				b.size()[i] + (p[i] - end));
	}

	return b;
}

/**
\brief Take the bounding box of two boxes
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>
*/
template<typename T,fcppt::math::size_type N>
fcppt::math::box::object<T,N> const
extend_bounding_box(
	fcppt::math::box::object<T,N> const &a,
	fcppt::math::box::object<T,N> const &b)
{
	fcppt::math::box::object<T,N> result;

	for (fcppt::math::size_type i = 0; i < N; ++i)
	{
		result.pos(
			i,
			std::min(
				a.pos()[i],
				b.pos()[i]));

		result.size(
			i,
			std::max(
				a.pos()[i] + a.size()[i],
				b.pos()[i] + b.size()[i]) -
			result.pos()[i]);
	}

	return result;
}
}
}
}

#endif
