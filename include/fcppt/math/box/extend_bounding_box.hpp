//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED

#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/contains_point.hpp>
#include <fcppt/math/box/init.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/preprocessor/const.hpp>
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
\brief Extend a box to fit a point in it
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

The result will either be the same box (if the point is contained in the box)
or a box that's just big enough to hold the given point.
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
> const
extend_bounding_box(
	fcppt::math::box::object<
		T,
		N
	> const _box,
	typename
	fcppt::math::box::object<
		T,
		N
	>::vector const _pos
)
{
	return
		fcppt::math::box::contains_point(
			_box,
			_pos
		)
		?
			_box
		:
			fcppt::math::box::init<
				fcppt::math::box::object<
					T,
					N
				>
			>(
				[
					&_pos,
					&_box
				](
					fcppt::math::size_type const _index
				)
				{
					return
						_pos[
							_index
						]
						<
						_box.pos(
							_index
						)
						?
							fcppt::make_homogenous_pair(
								_pos[
									_index
								],
								_box.size(
									_index
								)
								+
								_box.pos(
									_index
								)
								-
								_pos[
									_index
								]
							)
						:
							fcppt::make_homogenous_pair(
								_box.pos(
									_index
								),
								_pos[
									_index
								]
								>
								_box.max(
									_index
								)
								?
									_box.size(
										_index
									)
									+
									_pos[
										_index
									]
									-
									_box.max(
										_index
									)
								:
									_box.size(
										_index
									)
							)
						;
				}
			)
		;
}

/**
\brief Take the bounding box of two boxes
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
> const
extend_bounding_box(
	fcppt::math::box::object<
		T,
		N
	> const &_box1,
	fcppt::math::box::object<
		T,
		N
	> const &_box2
)
{
	return
		fcppt::math::box::init<
			fcppt::math::box::object<
				T,
				N
			>
		>(
			[
				&_box1,
				&_box2
			](
				fcppt::math::size_type const _index
			)
			{
				T const pos(
					std::min(
						_box1.pos(
							_index
						),
						_box2.pos(
							_index
						)
					)
				);

				return
					fcppt::make_homogenous_pair(
						pos,
						std::max(
							_box1.max(
								_index
							),
							_box2.max(
								_index
							)
							-
							pos
						)
					);
			}
		);
}

}
}
}

#endif
