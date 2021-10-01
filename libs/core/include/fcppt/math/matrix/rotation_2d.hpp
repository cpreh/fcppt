//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_ROTATION_2D_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_2D_HPP_INCLUDED

#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::matrix
{
/**
\brief Calculates a two dimensional rotation matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\param _angle The angle to rotate about

The resulting matrix will be a static one.
*/
template <typename T>
fcppt::math::matrix::static_<T, 2, 2> rotation_2d(T const _angle)
{
  T const sinx{std::sin(_angle)};

  T const cosx{std::cos(_angle)};

  return fcppt::math::matrix::static_<T, 2, 2>{
      fcppt::math::matrix::row(cosx, -sinx), fcppt::math::matrix::row(sinx, cosx)};
}

}

#endif
