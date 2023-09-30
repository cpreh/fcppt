//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_INT_TO_FLOAT_HPP_INCLUDED
#define FCPPT_CAST_INT_TO_FLOAT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Converts an int to a float

\ingroup fcpptcasts

Converts the integer \a _source to the float type specified by \a Dest by
truncating like <code>static_cast</code>. This cast is unsafe and should be
used with care.

\tparam Source Must be an integral type

\tparam Dest Must be a floating point type
*/
template <typename Dest, typename Source>
inline constexpr Dest int_to_float(Source const _source) noexcept
{
  static_assert(
      std::is_integral_v<Source> && std::is_floating_point_v<Dest>,
      "int_to_float can only cast from integral types to floating point types");

  return static_cast<Dest>(_source);
}

}

#endif
