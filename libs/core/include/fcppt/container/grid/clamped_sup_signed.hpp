//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_CLAMPED_SUP_SIGNED_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_CLAMPED_SUP_SIGNED_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/clamp.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief Clamps a signed position to a grid's size

\ingroup fcpptcontainergrid
*/
template <typename Dest, typename Source, fcppt::container::grid::size_type Size>
fcppt::container::grid::sup<Dest, Size> clamped_sup_signed(
    fcppt::container::grid::pos<Source, Size> const _pos,
    fcppt::container::grid::dim<Dest, Size> const _size)
{
  static_assert(std::is_signed_v<Source>, "Source must be signed");

  static_assert(std::is_unsigned_v<Dest>, "Dest must be unsigned");

  return fcppt::container::grid::sup<Dest, Size>(
      fcppt::math::vector::init<fcppt::container::grid::pos<Dest, Size>>(
          [&_pos, &_size]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
          {
            return fcppt::cast::to_unsigned(
                fcppt::math::clamp(
                    fcppt::math::vector::at<Index>(_pos),
                    fcppt::literal<Source>(0),
                    fcppt::cast::to_signed(fcppt::math::dim::at<Index>(_size)))
                    .get_unsafe());
          }));
}
}

#endif
