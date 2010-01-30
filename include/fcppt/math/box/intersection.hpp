//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/intersects.hpp>
#include <fcppt/math/size_type.hpp>
#include <algorithm>

namespace fcppt
{
namespace math
{
namespace box
{

template<
	typename T,
	size_type N
>
basic<T, N> const
intersection(
	basic<T, N> const &a,
	basic<T, N> const &b
)
{
	if(
		!intersects(
			a,
			b
		)
	)
		return basic<T, N>::null();

	basic<T, N> ret;

	for(
		size_type i = 0;
		i < N;
		++i
	)
	{
		ret.pos(
			i,
			std::max(
				a.pos(i),
				b.pos(i)
			)
		);

		ret.dimension(
			i,
			std::min(
				a.max(i),
				b.max(i)
			)
			- ret.pos(i)
		);
	}

	return ret;
}

}
}
}

#endif
