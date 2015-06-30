//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MIN_FROM_POS_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MIN_FROM_POS_FWD_HPP_INCLUDED

#include <fcppt/container/grid/min_fwd.hpp>
#include <fcppt/container/grid/pos.hpp>


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
min_from_pos
=
fcppt::container::grid::min<
	typename
	Pos::value_type,
	Pos::static_size::value
>;

}
}
}

#endif
