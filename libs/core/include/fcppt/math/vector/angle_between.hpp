//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_ANGLE_BETWEEN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ANGLE_BETWEEN_HPP_INCLUDED

#include <fcppt/math/div.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::vector
{
/**
\brief Calculates the angle between two floating point vectors

\ingroup fcpptmathvector

The function returns nothing if any of the two vectors have length zero.

If you want to calculate the angle between two vectors whose value type is not
a floating point type, see #fcppt::math::vector::angle_between_cast .

If you want to calculate the signed angle between two 2D vectors, use
#fcppt::math::vector::signed_angle_between  or
#fcppt::math::vector::signed_angle_between_cast .

\see fcppt::math::vector::angle_between_cast
\see fcppt::math::vector::signed_angle_between
\see fcppt::math::vector::signed_angle_between_cast

\warning
The behaviour is undefined if \p _from or \p _to are very close to zero.
*/
template <typename T, fcppt::math::size_type N, typename S1, typename S2>
fcppt::optional::object<T> angle_between(
    fcppt::math::vector::object<T, N, S1> const &_from,
    fcppt::math::vector::object<T, N, S2> const &_to)
{
  static_assert(
      std::is_floating_point_v<T>,
      "angle_between can only be used on vectors of floating-point type");

  return fcppt::optional::map(
      fcppt::math::div(
          fcppt::math::vector::dot(_from, _to),
          fcppt::math::vector::length(_from) * fcppt::math::vector::length(_to)),
      [](T const _angle) { return std::acos(_angle); });
}

}

#endif
