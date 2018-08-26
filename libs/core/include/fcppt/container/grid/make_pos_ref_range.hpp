//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_REF_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_REF_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_ref_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/pos_ref_range_impl.hpp>
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/math/dim/to_vector.hpp>
#include <fcppt/math/vector/null.hpp>
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
\brief A pos ref range over a grid

\ingroup fcpptcontainergrid
*/
template<
	typename Grid
>
inline
fcppt::container::grid::pos_ref_range<
	Grid
>
make_pos_ref_range(
	Grid &_grid
)
{
	typedef
	fcppt::container::grid::pos_type<
		std::remove_cv_t<
			Grid
		>
	>
	pos;

	return
		fcppt::container::grid::make_pos_ref_range_start_end(
			_grid,
			fcppt::container::grid::min_from_pos<
				pos
			>(
				fcppt::math::vector::null<
					pos
				>()
			),
			fcppt::container::grid::sup_from_pos<
				pos
			>(
				fcppt::math::dim::to_vector(
					_grid.size()
				)
			)
		);
}

}
}
}

#endif
