//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_SCALING_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_SCALING_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/object_impl.hpp>

namespace fcppt::math::matrix
{
/**
\brief Calculates a 4x4 scaling matrix

\ingroup fcpptmathmatrix

\param _x Scaling in x direction

\param _y Scaling in y direction

\param _z Scaling in z direction
*/
template <typename T>
fcppt::math::matrix::static_<
    T,
    4,
    4>
scaling(
    T const _x, // NOLINT(readability-avoid-const-params-in-decls)
    T const _y, // NOLINT(readability-avoid-const-params-in-decls)
    T const _z // NOLINT(readability-avoid-const-params-in-decls)
)
{
  T const zero{fcppt::literal<T>(0)};

  T const one{fcppt::literal<T>(1)};

  return fcppt::math::matrix::static_<T, 4, 4>(
      fcppt::math::matrix::row(_x, zero, zero, zero),
      fcppt::math::matrix::row(zero, _y, zero, zero),
      fcppt::math::matrix::row(zero, zero, _z, zero),
      fcppt::math::matrix::row(zero, zero, zero, one));
}

/// Calculates a scaling matrix from a three dimensional vector
template <typename T, typename S>
inline fcppt::math::matrix::static_<T, 4, 4>
scaling(fcppt::math::vector::object<T, 3, S> const &_vec)
{
  return fcppt::math::matrix::scaling(_vec.x(), _vec.y(), _vec.z());
}

}

#endif
