//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_START_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_START_END_HPP_INCLUDED

#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Grid
>
inline
fcppt::container::grid::pos_range<
	Grid
> const
make_pos_range_start_end(
	Grid &_grid,
	typename Grid::pos const &_start,
	typename Grid::pos const &_end
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

	typedef
	fcppt::container::grid::pos_range<
		Grid
	>
	result_type;

	return
		result_type(
			_grid,
			typename
			result_type::min(
				_start
			),
			typename
			result_type::sup(
				_end
			)
		);
}

}
}
}

#endif
