//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_REF_RANGE_START_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_REF_RANGE_START_END_HPP_INCLUDED

#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/container/grid/pos_ref_range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A pos ref range over a sub-grid

\ingroup fcpptcontainergrid

Creates a pos ref range from \a _min to, but not including, \a _sup.
*/
template<
	typename Grid
>
inline
fcppt::container::grid::pos_ref_range<
	Grid
>
make_pos_ref_range_start_end(
	Grid &_grid,
	typename
	fcppt::container::grid::pos_ref_range<
		Grid
	>::min_type const _min,
	typename
	fcppt::container::grid::pos_ref_range<
		Grid
	>::sup_type const _sup
)
{
	static_assert(
		fcppt::container::grid::is_object<
			typename std::remove_const<
				Grid
			>::type
		>::value,
		"Grid must be a grid::object"
	);

	return
		fcppt::container::grid::pos_ref_range<
			Grid
		>(
			_grid,
			_min,
			_sup
		);
}

}
}
}

#endif
