//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DEG_TO_RAD_HPP_INCLUDED
#define FCPPT_MATH_DEG_TO_RAD_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <numbers>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Transforms degrees into radians
\ingroup fcpptmath
\tparam T A floating point type
*/
template <typename T>
inline T deg_to_rad(T const _deg)
{
  static_assert(std::is_floating_point_v<T>, "deg_to_rad can only be used on floating point types");

  return _deg * std::numbers::pi_v<T> /
         fcppt::literal<T>(
             180); // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
}

}
}

#endif
