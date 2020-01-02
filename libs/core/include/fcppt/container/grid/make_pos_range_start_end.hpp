//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_START_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_START_END_HPP_INCLUDED

#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/container/grid/sup.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A sub range over positions

\ingroup fcpptcontainergrid

Creates a range of positions from \a _min to, but not including, \a _sup.
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
inline
fcppt::container::grid::pos_range<
	SizeType,
	Size
>
make_pos_range_start_end(
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
		fcppt::container::grid::pos_range<
			SizeType,
			Size
		>(
			_min,
			_sup
		);
}

}
}
}

#endif
