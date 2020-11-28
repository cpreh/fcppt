//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_EXPONENTIAL_PADE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_EXPONENTIAL_PADE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/cast/int_to_float.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Calculates the matrix exponential e^A using a Pade approximation

\ingroup fcpptmathmatrix
*/
template <typename T, fcppt::math::size_type DN, typename S>
fcppt::math::matrix::static_<T, DN, DN>
exponential_pade(fcppt::math::matrix::object<T, DN, DN, S> const &_matrix)
{
  static_assert(
      std::is_floating_point_v<T>, "exponential_pade can only be used on floating point types");

  using matrix_type = fcppt::math::matrix::static_<T, DN, DN>;

  T const zero{fcppt::literal<T>(0)};

  T const one{fcppt::literal<T>(1)};

  T const two{fcppt::literal<T>(2)};

  T const j{
      std::max(zero, one + std::log(fcppt::math::matrix::infinity_norm(_matrix)) / std::log(two))};

  matrix_type const temp(std::pow(two, std::floor(-j)) * _matrix);

  matrix_type D(fcppt::math::matrix::identity<matrix_type>());

  matrix_type N(fcppt::math::matrix::identity<matrix_type>());

  matrix_type X(fcppt::math::matrix::identity<matrix_type>());

  T c{fcppt::literal<T>(1)};

  fcppt::math::size_type const q{6U};

  for (fcppt::math::size_type const k :
       fcppt::make_int_range(fcppt::literal<fcppt::math::size_type>(1U), q))
  {
    T const qf{fcppt::cast::int_to_float<T>(q)};

    T const kf{fcppt::cast::int_to_float<T>(k)};

    c = (c * (qf - kf + one)) / (kf * (two * qf - kf + one));

    X = temp * X;

    matrix_type const cX(c * X);

    N += cX;

    D += (k % 2U == 0U ? fcppt::literal<T>(1) : fcppt::literal<T>(-1)) * cX;
  }

  X = fcppt::math::matrix::inverse(D) * N;

  matrix_type result(X);

  for ( // NOLINT(clang-analyzer-security.FloatLoopCounter)
      T count{fcppt::literal<T>(0)}; count < j; ++count // NOLINT(cert-flp30-c)
  )
  {
    result = result * result;
  }

  return result;
}

}
}
}

#endif
