//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_TRANSFORM_DIRECTION_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSFORM_DIRECTION_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/vector.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/narrow_cast.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/push_back.hpp>
#include <fcppt/math/vector/static.hpp>

namespace fcppt::math::matrix
{
/**
\brief Multiplies a 4x4 matrix by a 3D vector, adding 0 for w, returns a 3D vector

\ingroup fcpptmathmatrix

\param _matrix A 4x4 matrix

\param _vector A 3D vector

\see fcppt::math::matrix::transform_point
*/
template <typename T, typename S1, typename S2>
fcppt::math::vector::static_<T, 3> transform_direction(
    fcppt::math::matrix::object<T, 4, 4, S1> const &_matrix,
    fcppt::math::vector::object<T, 3, S2> const &_vector)
{
  return fcppt::math::vector::narrow_cast<fcppt::math::vector::static_<T, 3>>(
      _matrix * fcppt::math::vector::push_back(_vector, fcppt::literal<T>(0)));
}

}

#endif
