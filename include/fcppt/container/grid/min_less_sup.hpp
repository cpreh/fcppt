//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MIN_LESS_SUP_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MIN_LESS_SUP_HPP_INCLUDED

#include <fcppt/tag_value.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/int_range_count.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Checks if min is strictly less than sup

\ingroup fcpptcontainergrid

Checks if \a _min is strictly less than \a _sup. If this is false, the range
denoted by \a _min and \a _sup is empty.
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
bool
min_less_sup(
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
	return
		fcppt::algorithm::all_of(
			fcppt::math::int_range_count<
				Size
			>{},
			[
				&_min,
				&_sup
			](
				auto const _index
			)
			{
				auto const index(
					fcppt::tag_value(
						_index
					)
				);

				return
					fcppt::math::at_c<
						index
					>(
						_min.get()
					)
					<
					fcppt::math::at_c<
						index
					>(
						_sup.get()
					);
			}
		);
}

}
}
}

#endif
