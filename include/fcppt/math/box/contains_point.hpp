//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Test if a box contains a point
\ingroup fcpptmathbox
\tparam NBox The box's (and point's) dimension
\tparam NPoint The point's dimension (dynamic points are allowed)
\tparam S The point's storage type
\tparam T The box's (and point's) <code>value_type</code>
\param _box The box to test
\param _point The point to test
*/
template<
	typename T,
	typename S,
	size_type NBox,
	typename NPoint
>
bool
contains_point(
	box::basic<T, NBox> const &_box,
	vector::basic<T, NPoint, S> const &_point
)
{
	bool ret = true;

	for(
		math::size_type i = 0;
		i < NBox;
		++i
	)
		ret = ret &&
			_point[i] >= _box.pos(i)
			&& _point[i] < _box.max(i);

	return ret;
}

}
}
}

#endif
