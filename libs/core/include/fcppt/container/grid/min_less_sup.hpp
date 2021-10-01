//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_MIN_LESS_SUP_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MIN_LESS_SUP_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/at.hpp>

namespace fcppt::container::grid
{
/**
\brief Checks if min is strictly less than sup

\ingroup fcpptcontainergrid

Checks if \a _min is strictly less than \a _sup. If this is false, the range
denoted by \a _min and \a _sup is empty.
*/
template <typename SizeType, fcppt::container::grid::size_type Size>
bool min_less_sup(
    fcppt::container::grid::min<SizeType, Size> const _min,
    fcppt::container::grid::sup<SizeType, Size> const _sup)
{
  return fcppt::algorithm::all_of(
      fcppt::math::int_range_count<Size>{},
      [&_min, &_sup]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>)
      {
        return fcppt::math::vector::at<Index>(_min.get()) <
               fcppt::math::vector::at<Index>(_sup.get());
      });
}

}

#endif
