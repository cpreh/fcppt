//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/vector/at.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns the next position in a grid range

\ingroup fcpptcontainergrid

Given a range by \a _min and \a _sup, returns the next position after \a
_current.
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos<
	SizeType,
	Size
>
next_position(
	fcppt::container::grid::pos<
		SizeType,
		Size
	> const _current,
	fcppt::container::grid::min<
		SizeType,
		Size
	> const _min,
	fcppt::container::grid::sup<
		SizeType,
		Size
	> const _sup
)
{
	typedef
	fcppt::container::grid::pos<
		SizeType,
		Size
	>
	result_type;

	result_type result{
		_current
	};

	++result.x();

	return
		fcppt::algorithm::fold(
			fcppt::math::int_range_count<
				Size
				-
				1u
			>{},
			result,
			[
				&_min,
				&_sup
			](
				auto const _index,
				result_type _result
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

				if(
					fcppt::math::vector::at<
						index::value
					>(
						_result
					)
					==
					fcppt::math::vector::at<
						index::value
					>(
						_sup.get()
					)
				)
				{
					fcppt::math::vector::at<
						index::value
					>(
						_result
					) =
						fcppt::math::vector::at<
							index::value
						>(
							_min.get()
						);

					++
					fcppt::math::vector::at<
						index::value
						+
						1u
					>(
						_result
					);
				}

				return
					_result;
			}
		);
}

}
}
}

#endif
