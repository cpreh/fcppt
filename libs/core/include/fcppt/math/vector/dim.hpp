//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED

#include <fcppt/math/div.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/sequence.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/detail/dim_map.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Adds a dim to a vector.

\ingroup fcpptmathvector
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::math::vector::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, +, R), N> operator+(
    fcppt::math::vector::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::vector::detail::dim_map(
      _left, _right, [](L const &_left_elem, R const &_right_elem) {
        return _left_elem + _right_elem;
      });
}

/**
\brief Subtracts a dim from a vector.

\ingroup fcpptmathvector
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::math::vector::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, -, R), N> operator-(
    fcppt::math::vector::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::vector::detail::dim_map(
      _left, _right, [](L const &_left_elem, R const &_right_elem) {
        return _left_elem - _right_elem;
      });
}

/**
\brief Multiplies a vector by a dim.

\ingroup fcpptmathvector
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::math::vector::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R), N> operator*(
    fcppt::math::vector::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::vector::detail::dim_map(
      _left, _right, [](L const &_left_elem, R const &_right_elem) {
        return _left_elem * _right_elem;
      });
}

/**
\brief Divides a vector by a dim.

\ingroup fcpptmathvector
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::optional::object<
    fcppt::math::vector::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R), N>>
operator/(
    fcppt::math::vector::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::vector::sequence(fcppt::math::vector::detail::dim_map(
      _left, _right, [](L const &_left_elem, R const &_right_elem) {
        return fcppt::math::div(_left_elem, _right_elem);
      }));
}

}
}
}

#endif
