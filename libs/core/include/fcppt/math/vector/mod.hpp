//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED

#include <fcppt/math/mod.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/sequence.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Calculate vector modulo a scalar

\ingroup fcpptmathvector
*/
template <typename T, fcppt::math::size_type N, typename S>
fcppt::optional::object<fcppt::math::vector::static_<T, N>>
mod(fcppt::math::vector::object<T, N, S> const &_arg, T const _div)
{
  return fcppt::math::detail::sequence<fcppt::math::vector::static_<T, N>>(
      fcppt::math::vector::init<fcppt::math::vector::static_<fcppt::optional::object<T>, N>>(
          [&_arg, _div]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
          { return fcppt::math::mod(fcppt::math::vector::at<Index>(_arg), _div); }));
}

/**
\brief Calculate vector modulo a vector

\ingroup fcpptmathvector
*/
template <typename T, fcppt::math::size_type N, typename S1, typename S2>
fcppt::optional::object<fcppt::math::vector::static_<T, N>>
mod(fcppt::math::vector::object<T, N, S1> const &_v0,
    fcppt::math::vector::object<T, N, S2> const &_v1)
{
  return fcppt::math::detail::sequence<fcppt::math::vector::static_<T, N>>(
      fcppt::math::vector::init<fcppt::math::vector::static_<fcppt::optional::object<T>, N>>(
          [&_v0, &_v1]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
          {
            return fcppt::math::mod(
                fcppt::math::vector::at<Index>(_v0), fcppt::math::vector::at<Index>(_v1));
          }));
}

}
}
}

#endif
