//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/div.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/unary_type.hpp>
#include <fcppt/math/dim/binary_map.hpp>
#include <fcppt/math/dim/map.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/sequence.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt::math::dim
{
/**
\brief Negates a dim.

\ingroup fcpptmathdim
*/
template <typename T, fcppt::math::size_type N, typename S>
inline fcppt::math::dim::static_<FCPPT_MATH_DETAIL_UNARY_TYPE(T, -), N>
operator-(fcppt::math::dim::object<T, N, S> const &_left)
{
  return fcppt::math::dim::map(_left, [](T const &_elem) { return -_elem; });
}

/**
\brief Adds a dim to a dim.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, +, R), N> operator+(
    fcppt::math::dim::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::dim::binary_map(_left, _right, [](L const &_left_elem, R const &_right_elem) {
    return _left_elem + _right_elem;
  });
}

/**
\brief Subtracts a dim from a dim.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, -, R), N> operator-(
    fcppt::math::dim::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::dim::binary_map(_left, _right, [](L const &_left_elem, R const &_right_elem) {
    return _left_elem - _right_elem;
  });
}

/**
\brief Multiplies a dim by a dim.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R), N> operator*(
    fcppt::math::dim::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::dim::binary_map(_left, _right, [](L const &_left_elem, R const &_right_elem) {
    return _left_elem * _right_elem;
  });
}

/**
\brief Divides a dim by a dim.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S1, typename S2>
inline fcppt::optional::object<fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R), N>>
operator/(
    fcppt::math::dim::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right)
{
  return fcppt::math::dim::sequence(
      fcppt::math::dim::binary_map(_left, _right, [](L const &_left_elem, R const &_right_elem) {
        return fcppt::math::div(_left_elem, _right_elem);
      }));
}

/**
\brief Multiplies a dim by a scalar on the right.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S>
inline fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R), N>
operator*(fcppt::math::dim::object<L, N, S> const &_left, R const &_right)
{
  return fcppt::math::dim::map(
      _left, [&_right](L const &_left_elem) { return _left_elem * _right; });
}

/**
\brief Multiplies a dim by a scalar on the left.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S>
inline fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R), N>
operator*(L const &_left, fcppt::math::dim::object<R, N, S> const &_right)
{
  return fcppt::math::dim::map(
      _right, [&_left](R const &_right_elem) { return _left * _right_elem; });
}

/**
\brief Divides a dim by a scalar.

\ingroup fcpptmathdim
*/
template <typename L, typename R, fcppt::math::size_type N, typename S>
inline fcppt::optional::object<fcppt::math::dim::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R), N>>
operator/(fcppt::math::dim::object<L, N, S> const &_left, R const &_right)
{
  return fcppt::math::dim::sequence(fcppt::math::dim::map(
      _left, [&_right](L const &_left_elem) { return fcppt::math::div(_left_elem, _right); }));
}

}

#endif
