//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_INIT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INIT_HPP_INCLUDED

#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/init.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/matrix/detail/index_absolute.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Initializes a matrix

\ingroup fcpptmathmatrix

Calls <code>_function</code> for every index of the matrix.

\tparam Matrix Must be a matrix

\tparam Function Must be a polymorphic function of type <code>Matrix::value_type
(fcppt::math::matrix::index<R,C>)</code>
*/
template <typename Matrix, typename Function>
inline Matrix init(Function const &_function)
{
  static_assert(fcppt::math::matrix::is_matrix<Matrix>::value, "Matrix must be a matrix");

  return fcppt::math::detail::init<Matrix>(
      [&_function]<fcppt::math::size_type Abs>(fcppt::math::size_constant<Abs>)
      {
        return _function(
            fcppt::math::matrix::detail::index_absolute<Matrix::static_columns::value, Abs>{});
      });
}

}
}
}

#endif
