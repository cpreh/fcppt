//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_HPP_INCLUDED

#include <fcppt/math/vector/arithmetic.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::vector
{
/**
\brief Calculates the signed angle between two 2D vectors.

\ingroup fcpptmathvector

Uses #fcppt::math::vector::atan2 on the difference between the two
vectors. In case this fails, nothing is returned.

If you want to calculate the angle between two vectors whose value type is not
a floating-point type, see #fcppt::math::vector::signed_angle_between_cast.

If you want to calculate the (unsigned) angle between two vectors of higher
dimensions, use #fcppt::math::vector::angle_between or
#fcppt::math::vector::angle_between_cast.

\see fcppt::math::vector::signed_angle_between_cast
\see fcppt::math::vector::angle_between
\see fcppt::math::vector::angle_between_cast

\tparam T Must be a floating-point type.
*/
template <typename T, typename S1, typename S2>
fcppt::optional::object<T> signed_angle_between(
    fcppt::math::vector::object<T, 2, S1> const &_from,
    fcppt::math::vector::object<T, 2, S2> const &_to)
{
  static_assert(
      std::is_floating_point_v<T>,
      "signed_angle_between can only be used on floating-point vector types");

  return fcppt::math::vector::atan2(_to - _from);
}

}

#endif
