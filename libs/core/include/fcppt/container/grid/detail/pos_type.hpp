//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_POS_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_POS_TYPE_HPP_INCLUDED

#include <fcppt/container/grid/is_object.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Grid
>
struct pos_type
{
	static_assert(
		fcppt::container::grid::is_object<
			Grid
		>::value,
		"Grid must be a grid"
	);

	typedef
	typename
	Grid::pos
	type;
};

}
}
}
}

#endif
