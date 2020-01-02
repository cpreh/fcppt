//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_REF_CRANGE_START_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_REF_CRANGE_START_END_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_ref_range_start_end.hpp>
#include <fcppt/container/grid/pos_ref_range_impl.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A const pos ref range over a sub-grid

\ingroup fcpptcontainergrid

Creates a const pos ref range from \a _min to, but not including, \a _sup.
*/
template<
	typename Grid
>
inline
fcppt::container::grid::pos_ref_range<
	Grid const
>
make_pos_ref_crange_start_end(
	Grid const &_grid,
	typename
	fcppt::container::grid::pos_ref_range<
		Grid const
	>::min_type const _min,
	typename
	fcppt::container::grid::pos_ref_range<
		Grid const
	>::sup_type const _sup
)
{
	return
		fcppt::container::grid::make_pos_ref_range_start_end(
			_grid,
			_min,
			_sup
		);
}

}
}
}

#endif
