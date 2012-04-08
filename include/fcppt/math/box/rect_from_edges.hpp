//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_RECT_FROM_EDGES_HPP_INCLUDED
#define FCPPT_MATH_BOX_RECT_FROM_EDGES_HPP_INCLUDED

#include <fcppt/math/box/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Constructs a rectangle from its four edges instead of a position and a dimension
\ingroup fcpptmathbox
\tparam Scalar The box's <code>value_type</code>
*/
template<
	typename Scalar
>
fcppt::math::box::object
<
	Scalar,
	2
> const
rect_from_edges(
	Scalar const _left,
	Scalar const _top,
	Scalar const _right,
	Scalar const _bottom
)
{
	typedef typename
	fcppt::math::box::object
	<
		Scalar,
		2
	>::vector
	vector;

	typedef typename
	fcppt::math::box::object
	<
		Scalar,
		2
	>::dim
	dim;

	return
		fcppt::math::box::object
		<
			Scalar,
			2
		>(
			vector(
				_left,
				_top),
			dim(
				_right - _left,
				_bottom - _top
			)
		);
}

}
}
}

#endif
