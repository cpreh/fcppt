//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_CORNER_POINTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_CORNER_POINTS_HPP_INCLUDED

#include <fcppt/array/get.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/math/power_of_2.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/to_vector.hpp>
#include <fcppt/math/vector/arithmetic.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/bit_strings.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::box
{
/**
\brief Returns the 2^N corner points (vertices) of the given box.

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
fcppt::array::object<fcppt::math::vector::static_<T, N>, fcppt::math::power_of_2<std::size_t>(N)>
corner_points(fcppt::math::box::object<T, N> const &_box)
{
  using vector_type = fcppt::math::vector::static_<T, N>;

  using result_type = fcppt::array::object<vector_type, fcppt::math::power_of_2<std::size_t>(N)>;

  result_type const corners(fcppt::math::vector::bit_strings<T, N>());

  return fcppt::array::init<result_type>(
      [&_box, &corners]<std::size_t Index>(std::integral_constant<std::size_t, Index>)
      {
        return _box.pos() +
               (fcppt::array::get<Index>(corners) * fcppt::math::dim::to_vector(_box.size()));
      });
}

}

#endif
