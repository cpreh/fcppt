//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_BOX_DISTANCE_HPP_INCLUDED

#include <fcppt/math/interval_distance.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/interval.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Calculates the interval distance between all box dimensions

\ingroup fcpptmathbox
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::vector::static_<
	T,
	N
>
distance(
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
		fcppt::math::vector::init<
			fcppt::math::vector::static_<
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
				return
					fcppt::math::interval_distance(
						fcppt::math::box::interval<
							_index
						>(
							_box1
						),
						fcppt::math::box::interval<
							_index
						>(
							_box2
						)
					);
			}
		);
}

}
}
}

#endif
