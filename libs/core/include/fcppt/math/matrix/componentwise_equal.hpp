//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/componentwise_equal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Compares two floating point matrices componentwise using an epsilon

\ingroup fcpptmathmatrix

\param _m1 The first matrix

\param _m2 The second matrix

\param _epsilon The epsilon to compare with
*/
template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S1, typename S2>
inline bool componentwise_equal(
    fcppt::math::matrix::object<T, R, C, S1> const &_m1,
    fcppt::math::matrix::object<T, R, C, S2> const &_m2,
    T const _epsilon)
{
  return fcppt::math::detail::componentwise_equal(_m1, _m2, _epsilon);
}

}
}
}

#endif
