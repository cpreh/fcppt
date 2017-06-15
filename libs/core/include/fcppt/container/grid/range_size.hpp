//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_RANGE_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_RANGE_SIZE_HPP_INCLUDED

#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/range_dim.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/dim/contents.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief The number of elements in a grid range

\ingroup fcpptcontainergrid

The number of elements in the range given by \a _min and \a _sup.
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
inline
SizeType
range_size(
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
		fcppt::math::dim::contents(
			fcppt::container::grid::range_dim(
				_min,
				_sup
			)
		);
}

}
}
}

#endif
