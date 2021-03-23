//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_COMPARISON_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/array_equal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Compares two matrices component-wise

\ingroup fcpptmathmatrix

\warning
This uses <code>T</code>'s equality comparison operator, so be careful if you
want to compare floating point matrices.
*/
template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S1, typename S2>
inline bool operator==(
    fcppt::math::matrix::object<T, R, C, S1> const &_m1,
    fcppt::math::matrix::object<T, R, C, S2> const &_m2)
{
  return fcppt::math::detail::array_equal(_m1, _m2);
}

/**
\brief Compares two matrices component-wise

\ingroup fcpptmathmatrix

\warning
This uses <code>T</code>'s inequality comparison operator, so be careful if you
want to compare floating point matrices.
*/
template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S1, typename S2>
inline bool operator!=(
    fcppt::math::matrix::object<T, R, C, S1> const &_m1,
    fcppt::math::matrix::object<T, R, C, S2> const &_m2)
{
  return !(_m1 == _m2);
}

}
}
}

#endif
