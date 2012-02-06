//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/contains_point.hpp>


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
template<typename T,size_type N>
basic<T,N> const
extend_bounding_box(
	basic<T,N> b,
	typename basic<T,N>::vector const &p)
{
	if (fcppt::math::box::contains_point(
		b,
		p))
		return b;

	for (size_type i = 0; i < N; ++i)
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
}
}
}

#endif
