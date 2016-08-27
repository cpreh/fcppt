//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_FWD_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief The type used to index a grid

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type N
>
using pos
=
fcppt::math::vector::static_<
	SizeType,
	N
>;

}
}
}

#endif
