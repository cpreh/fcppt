//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_ROTATION_AXIS_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_AXIS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::matrix
{
/**
\brief Calculates a 4x4 rotation matrix around an arbitrary axis given as a
unit vector

\ingroup fcpptmathmatrix

\tparam T The matrix's <code>value_type</code>

\param _angle The angle to rotate about

\param _vector The axis to rotate around

The resulting matrix will be static.

\see
fcppt::math::matrix::rotation_x

\see
fcppt::math::matrix::rotation_y

\see
fcppt::math::matrix::rotation_z

\see
fcppt::math::matrix::rotation_axis
*/
template <typename T, typename S>
fcppt::math::matrix::static_<T, 4, 4>
rotation_axis(T const _angle, fcppt::math::vector::object<T, 3, S> const &_vector)
{
  T const sinx{std::sin(_angle)};

  T const cosx{std::cos(_angle)};

  T const one{fcppt::literal<T>(1)};

  T const cosxc{one - cosx};

  T const x{_vector.x()};

  T const y{_vector.y()};

  T const z{_vector.z()};

  T const zero{fcppt::literal<T>(0)};

  return fcppt::math::matrix::static_<T, 4, 4>(
      fcppt::math::matrix::row(
          cosx + x * x * cosxc, x * y * cosxc - z * sinx, x * z * cosxc + y * sinx, zero),
      fcppt::math::matrix::row(
          x * y * cosxc + z * sinx, cosx + y * y * cosxc, y * z * cosxc - x * sinx, zero),
      fcppt::math::matrix::row(
          x * z * cosxc - y * sinx, y * z * cosxc + x * sinx, cosx + z * z * cosxc, zero),
      fcppt::math::matrix::row(zero, zero, zero, one));
}

}

#endif
