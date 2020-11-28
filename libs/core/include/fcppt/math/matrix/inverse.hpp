//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Calculates the inverse matrix, uses fcppt::math::matrix::adjugate and
fcppt::math::matrix::determinant.

\ingroup fcpptmathmatrix

\warning
Consider this a slow operation
*/
template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::matrix::static_<T, N, N>
inverse(fcppt::math::matrix::object<T, N, N, S> const &_matrix)
{
  T const det{fcppt::math::matrix::determinant(_matrix)};

  return (fcppt::literal<T>(1) / det) * fcppt::math::matrix::adjugate(_matrix);
}

}
}
}

#endif
