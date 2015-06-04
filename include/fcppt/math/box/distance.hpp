//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_BOX_DISTANCE_HPP_INCLUDED

#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/algorithm/array_fold.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/interval_distance.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


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
	typedef
	fcppt::math::vector::static_<
		T,
		N
	>
	result_type;

	return
		// TODO: Abstract this in a better way
		result_type(
			fcppt::algorithm::array_fold<
				typename
				result_type::storage_type
			>(
				[
					&_box1,
					&_box2
				](
					std::size_t const _index
				)
				{
					fcppt::math::size_type const index(
						fcppt::cast::size<
							fcppt::math::size_type
						>(
							_index
						)
					);

					return
						fcppt::math::interval_distance(
							fcppt::make_homogenous_pair(
								_box1.pos(
									index
								),
								_box1.max(
									index
								)
							),
							fcppt::make_homogenous_pair(
								_box2.pos(
									index
								),
								_box2.max(
									index
								)
							)
						);
				}
			)
		);
}

}
}
}

#endif
