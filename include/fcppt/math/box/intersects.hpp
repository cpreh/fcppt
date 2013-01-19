//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Tests if two boxes intersect
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>
*/
template<
	typename T,
	size_type N
>
bool
intersects(
	object<T, N> const &a,
	object<T, N> const &b
)
{
	bool ret = false;

	for(
		size_type i = 0;
		i < N;
		++i
	)
		ret = ret
			|| a.pos(i) > b.max(i)
			|| a.max(i) < b.pos(i);

	return !ret;
}

}
}
}

#endif
