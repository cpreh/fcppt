//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_CLAMPED_SUP_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_CLAMPED_SUP_HPP_INCLUDED

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
/**
\brief Clamps a position to a grid's size

\ingroup fcpptcontainergrid
*/
template <typename Source, fcppt::container::grid::size_type Size>
fcppt::container::grid::sup<Source, Size> clamped_sup(
    fcppt::container::grid::pos<Source, Size> const _pos,
    fcppt::container::grid::dim<Source, Size> const _size)
{
  static_assert(std::is_unsigned<Source>::value, "Source must be unsigned");

  return fcppt::container::grid::sup<Source, Size>(
      fcppt::math::vector::init<fcppt::container::grid::pos<Source, Size>>(
          [&_pos, &_size]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>) {
            return std::min(
                fcppt::math::vector::at<Index>(_pos), fcppt::math::dim::at<Index>(_size));
          }));
}

}
}
}

#endif
