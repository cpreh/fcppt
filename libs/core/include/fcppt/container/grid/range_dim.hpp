//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_RANGE_DIM_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_RANGE_DIM_HPP_INCLUDED

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/min_less_sup.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/dim/null.hpp>
#include <fcppt/math/vector/arithmetic.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/to_dim.hpp>

namespace fcppt::container::grid
{
/**
\brief The dimension of a grid range

\ingroup fcpptcontainergrid

The dimension of the range given by \a _min and \a _sup.
*/
template <typename SizeType, fcppt::container::grid::size_type Size>
fcppt::container::grid::dim<SizeType, Size> range_dim(
    fcppt::container::grid::min<SizeType, Size> const _min,
    fcppt::container::grid::sup<SizeType, Size> const _sup)
{
  return fcppt::container::grid::min_less_sup(_min, _sup)
             ? fcppt::math::vector::to_dim(_sup.get() - _min.get())
             : fcppt::math::dim::null<fcppt::container::grid::dim<SizeType, Size>>();
}

}

#endif
