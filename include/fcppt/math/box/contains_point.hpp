//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>


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
\tparam NPoint The point's dimension
\tparam S The point's storage type
\tparam T The box's (and point's) <code>value_type</code>
\param _box The box to test
\param _point The point to test
*/
template<
	typename T,
	typename S,
	fcppt::math::size_type NBox,
	typename NPoint
>
inline
bool
contains_point(
	fcppt::math::box::object<
		T,
		NBox
	> const &_box,
	fcppt::math::vector::object<
		T,
		NPoint,
		S
	> const &_point
)
{
	return
		fcppt::algorithm::all_of(
			fcppt::make_int_range_count(
				NBox
			),
			[
				&_box,
				&_point
			](
				fcppt::math::size_type const _index
			)
			{
				return
					_point[
						_index
					]
					>=
					_box.pos(
						_index
					)
					&&
					_point[
						_index
					]
					<
					_box.max(
						_index
					);
			}
		);
}

}
}
}

#endif
