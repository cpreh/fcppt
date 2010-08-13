#ifndef FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/contains_point.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
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
			b.dimension(
				i,
				b.dimension()[i] + (b.pos()[i] - p[i]));

			b.pos(
				i,
				p[i]);

			continue;
		}

		T const end = 
			static_cast<T>(
				b.pos()[i] + b.dimension()[i]);
		
		if (p[i] > end)
			b.dimension(
				i,
				b.dimension()[i] + (p[i] - end));
	}

	return b;
}
}
}
}

#endif
