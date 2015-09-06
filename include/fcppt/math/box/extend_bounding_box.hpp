//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED

#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/contains_point.hpp>
#include <fcppt/math/box/init.hpp>
#include <fcppt/math/box/max_at.hpp>
#include <fcppt/math/box/max_at_c.hpp>
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
>
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
					auto const _index
				)
				{
					return
						fcppt::math::at_c<
							_index
						>(
							_pos
						)
						<
						fcppt::math::at_c<
							_index
						>(
							_box.pos()
						)
						?
							fcppt::make_homogenous_pair(
								fcppt::math::at_c<
									_index
								>(
									_pos
								),
								fcppt::math::at_c<
									_index
								>(
									_box.size()
								)
								+
								fcppt::math::at_c<
									_index
								>(
									_box.pos()
								)
								-
								fcppt::math::at_c<
									_index
								>(
									_pos
								)
							)
						:
							fcppt::make_homogenous_pair(
								fcppt::math::at_c<
									_index
								>(
									_box.pos()
								),
								fcppt::math::at_c<
									_index
								>(
									_pos
								)
								>
								fcppt::math::box::max_at_c<
									_index
								>(
									_box
								)
								?
									fcppt::math::at_c<
										_index
									>(
										_box.size()
									)
									+
									fcppt::math::at_c<
										_index
									>(
										_pos
									)
									-
									fcppt::math::box::max_at_c<
										_index
									>(
										_box
									)
								:
									fcppt::math::at_c<
										_index
									>(
										_box.size()
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
>
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
				auto const _index
			)
			{
				T const pos(
					std::min(
						fcppt::math::at_c<
							_index
						>(
							_box1.pos()
						),
						fcppt::math::at_c<
							_index
						>(
							_box2.pos()
						)
					)
				);

				return
					fcppt::make_homogenous_pair(
						pos,
						std::max(
							// TODO: constant max
							fcppt::math::box::max_at(
								_box1,
								_index
							),
							fcppt::math::box::max_at(
								_box2,
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
