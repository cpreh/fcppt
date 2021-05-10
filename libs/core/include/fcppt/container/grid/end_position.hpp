//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_END_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_END_POSITION_HPP_INCLUDED

#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/min_less_sup.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/init.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
/**
\brief The end position of a range

\ingroup fcpptcontainergrid

Returns the end position of a grid range that is formed by \a _min and \a _sup.
This position is usually further than one past the last element.
*/
template <typename SizeType, fcppt::container::grid::size_type Size>
fcppt::container::grid::pos<SizeType, Size> end_position(
    fcppt::container::grid::min<SizeType, Size> const _min,
    fcppt::container::grid::sup<SizeType, Size> const _sup)
{
  return fcppt::container::grid::min_less_sup(_min, _sup)
             ? fcppt::math::vector::init<fcppt::container::grid::pos<SizeType, Size>>(
                   [_min, _sup]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
                   {
                     return Index < Size - 1 ? fcppt::math::vector::at<Index>(_min.get())
                                             : fcppt::math::vector::at<Index>(_sup.get());
                   })
             : _min.get();
}

}
}
}

#endif
