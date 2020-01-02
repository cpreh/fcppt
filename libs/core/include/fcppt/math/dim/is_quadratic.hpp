//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/dim/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Checks if all elements of the dim are the same

\ingroup fcpptmathdim

\param _dim The dimension to check
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
bool
is_quadratic(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_dim
)
{
	return
		fcppt::algorithm::all_of(
			fcppt::math::int_range_count<
				N
			>{},
			[
				&_dim,
				_first =
					fcppt::math::dim::at<
						0
					>(
						_dim
					)
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				typedef
				fcppt::tag_type<
					decltype(
						_index
					)
				>
				index;

				return
					fcppt::math::dim::at<
						index::value
					>(
						_dim
					)
					==
					_first;
			}
		);
}

}
}
}

#endif
