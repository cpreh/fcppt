//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_CLAMPED_MIN_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_CLAMPED_MIN_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
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
\brief Clamps a signed position to min

\ingroup fcpptcontainergrid
*/
template <typename Source, fcppt::container::grid::size_type Size>
fcppt::container::grid::min<std::make_unsigned_t<Source>, Size>
clamped_min(fcppt::container::grid::pos<Source, Size> const _pos)
{
  static_assert(std::is_signed_v<Source>, "Source must be signed");

  using dest_type = std::make_unsigned_t<Source>;

  return fcppt::container::grid::min<dest_type, Size>(
      fcppt::math::vector::init<fcppt::container::grid::pos<dest_type, Size>>(
          [&_pos]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>) {
            return fcppt::cast::to_unsigned(
                std::max(fcppt::math::vector::at<Index>(_pos), fcppt::literal<Source>(0)));
          }));
}

}
}
}

#endif
