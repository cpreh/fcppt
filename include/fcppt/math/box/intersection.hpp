//          Copyright Carl Philipp Reh 2009 - 2011.
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

/// Calculates the intersecting box of @a _a and @a _b
/**
 * @return If there is no intersection, null will be returned
*/
template<
	typename T,
	size_type N
>
basic<T, N> const
intersection(
	basic<T, N> const &_a,
	basic<T, N> const &_b
)
{
	if(
		!box::intersects(
			_a,
			_b
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
				_a.pos(i),
				_b.pos(i)
			)
		);

		ret.size(
			i,
			std::min(
				_a.max(i),
				_b.max(i)
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
