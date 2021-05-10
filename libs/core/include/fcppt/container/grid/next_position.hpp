//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/at.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
/**
\brief Returns the next position in a grid range

\ingroup fcpptcontainergrid

Given a range by \a _min and \a _sup, returns the next position after \a
_current.
*/
template <typename SizeType, fcppt::container::grid::size_type Size>
fcppt::container::grid::pos<SizeType, Size> next_position(
    fcppt::container::grid::pos<SizeType, Size> const _current,
    fcppt::container::grid::min<SizeType, Size> const _min,
    fcppt::container::grid::sup<SizeType, Size> const _sup)
{
  using result_type = fcppt::container::grid::pos<SizeType, Size>;

  result_type result{_current};

  ++result.x();

  return fcppt::algorithm::fold(
      fcppt::math::int_range_count<Size - 1U>{},
      result,
      [&_min, &_sup]<fcppt::math::size_type Index>(
          fcppt::tag<fcppt::math::size_constant<Index>>, result_type _result)
      {
        if (fcppt::math::vector::at<Index>(_result) == fcppt::math::vector::at<Index>(_sup.get()))
        {
          fcppt::math::vector::at<Index>(_result) = fcppt::math::vector::at<Index>(_min.get());

          ++fcppt::math::vector::at<Index + 1U>(_result);
        }

        return _result;
      });
}

}
}
}

#endif
