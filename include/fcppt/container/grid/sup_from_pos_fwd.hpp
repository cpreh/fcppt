//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_SUP_FROM_POS_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SUP_FROM_POS_FWD_HPP_INCLUDED

#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Pos
>
using
sup_from_pos
=
fcppt::container::grid::sup<
	typename
	Pos::value_type,
	Pos::static_size::value
>;

}
}
}

#endif
