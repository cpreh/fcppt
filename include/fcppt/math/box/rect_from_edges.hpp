//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
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
inline
fcppt::math::box::object<
	Scalar,
	2
>
rect_from_edges(
	Scalar const _left,
	Scalar const _top,
	Scalar const _right,
	Scalar const _bottom
)
{
	typedef
	fcppt::math::box::object<
		Scalar,
		2
	>
	result_type;

	return
		result_type(
			typename
			result_type::vector(
				_left,
				_top
			),
			typename
			result_type::dim(
				_right - _left,
				_bottom - _top
			)
		);
}

}
}
}

#endif
