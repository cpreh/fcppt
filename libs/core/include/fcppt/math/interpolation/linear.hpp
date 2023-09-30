//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_INTERPOLATION_LINEAR_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_LINEAR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::interpolation
{
/**
\brief Interpolates between two values linearly

\ingroup fcpptmath

\tparam Float Must be a floating point type

\tparam Value Must support scalar multiplication with \a Float and addition
*/
template <typename Float, typename Value>
Value linear(Float const &_f, Value const &_v1, Value const &_v2)
{
  static_assert(
      std::is_floating_point_v<Float>,
      "interpolation::linear can only be used on floating point types");

  return (fcppt::literal<Float>(1) - _f) * _v1 + _f * _v2;
}

}

#endif
