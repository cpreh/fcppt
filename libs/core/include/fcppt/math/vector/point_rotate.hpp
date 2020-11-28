//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_POINT_ROTATE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_POINT_ROTATE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/rotation_2d.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Rotates a two dimensional point around another point

\ingroup fcpptmathvector

\param _point The point to rotate

\param _around The point to rotate around

\param _rot The rotation angle
*/
template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::vector::static_<T, N> point_rotate(
    fcppt::math::vector::object<T, N, S> const &_point,
    fcppt::math::vector::object<T, N, S> const &_around,
    T const _rot)
{
  return (fcppt::math::matrix::rotation_2d(_rot) * (_point - _around)) + _around;
}

}
}
}

#endif
