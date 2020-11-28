//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/binary_map.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/map.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Adds two matrices.

\ingroup fcpptmathmatrix
*/
template <
    typename Left,
    typename Right,
    fcppt::math::size_type R,
    fcppt::math::size_type C,
    typename S1,
    typename S2>
inline fcppt::math::matrix::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(Left, +, Right), R, C> operator+(
    fcppt::math::matrix::object<Left, R, C, S1> const &_left,
    fcppt::math::matrix::object<Right, R, C, S2> const &_right)
{
  return fcppt::math::matrix::binary_map(
      _left, _right, [](Left const &_left_elem, Right const &_right_elem) {
        return _left_elem + _right_elem;
      });
}

/**
\brief Subtracts one matrix from another.

\ingroup fcpptmathmatrix
*/
template <
    typename Left,
    typename Right,
    fcppt::math::size_type R,
    fcppt::math::size_type C,
    typename S1,
    typename S2>
inline fcppt::math::matrix::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(Left, -, Right), R, C> operator-(
    fcppt::math::matrix::object<Left, R, C, S1> const &_left,
    fcppt::math::matrix::object<Right, R, C, S2> const &_right)
{
  return fcppt::math::matrix::binary_map(
      _left, _right, [](Left const &_left_elem, Right const &_right_elem) {
        return _left_elem - _right_elem;
      });
}

/**
\brief Multiplies two matrices.

\ingroup fcpptmathmatrix
*/
template <
    typename L,
    typename R,
    fcppt::math::size_type N,
    fcppt::math::size_type M1,
    fcppt::math::size_type M2,
    typename S1,
    typename S2>
inline fcppt::math::matrix::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R), M1, M2> operator*(
    fcppt::math::matrix::object<L, M1, N, S1> const &_left,
    fcppt::math::matrix::object<R, N, M2, S2> const &_right)
{
  using result_type = fcppt::math::matrix::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R), M1, M2>;

  using value_type = fcppt::type_traits::value_type<result_type>;

  return fcppt::math::matrix::init<result_type>([&_left, &_right](auto const _index) {
    return fcppt::algorithm::fold(
        fcppt::math::int_range_count<N>{},
        fcppt::literal<value_type>(0),
        [_index, &_left, &_right](auto const _pos, value_type const _sum) {
          FCPPT_USE(_pos);

          using pos = fcppt::tag_type<decltype(_pos)>;

          return _sum + fcppt::math::matrix::at_r_c<_index.row(), pos::value>(_left) *
                            fcppt::math::matrix::at_r_c<pos::value, _index.column()>(_right);
        });
  });
}

/**
\brief Multiplies a matrix by a scalar.

\ingroup fcpptmathmatrix
*/
template <
    typename Left,
    typename Right,
    fcppt::math::size_type R,
    fcppt::math::size_type C,
    typename S>
inline fcppt::math::matrix::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right), R, C>
operator*(fcppt::math::matrix::object<Left, R, C, S> const &_left, Right const &_right)
{
  return fcppt::math::matrix::map(
      _left, [&_right](Left const &_left_element) { return _left_element * _right; });
}

/**
\brief Multiplies a matrix by a scalar.

\ingroup fcpptmathmatrix
*/
template <
    typename Left,
    typename Right,
    fcppt::math::size_type R,
    fcppt::math::size_type C,
    typename S>
inline fcppt::math::matrix::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right), R, C>
operator*(Left const &_left, fcppt::math::matrix::object<Right, R, C, S> const &_right)
{
  return fcppt::math::matrix::map(
      _right, [&_left](Right const &_right_element) { return _left * _right_element; });
}

}
}
}

#endif
