//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/intersects.hpp>
#include <fcppt/math/box/object_impl.hpp>
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
\brief Calculates the intersection of two boxes (which is, again, a box)
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

If there is no intersection, the null box will be returned.
*/
template<
	typename T,
	size_type N
>
object<T, N> const
intersection(
	object<T, N> const &_a,
	object<T, N> const &_b
)
{
	if(
		!box::intersects(
			_a,
			_b
		)
	)
		return object<T, N>::null();

	object<T, N> ret;

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
