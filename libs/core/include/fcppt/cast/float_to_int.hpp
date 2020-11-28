//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_FLOAT_TO_INT_HPP_INCLUDED
#define FCPPT_CAST_FLOAT_TO_INT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief Converts a float to a signed int

\ingroup fcpptcasts

Converts \a _source to an integer. The function ensures that only signed
integers can be used as destination types. If you need to cast to unsigned
integers, use #fcppt::cast::to_unsigned  in addition. This cast is
unsafe and should be used with care.

\tparam Source Must be a floating point type

\tparam Dest Must be a signed integer type
*/
template <typename Dest, typename Source>
inline constexpr Dest float_to_int(Source const _source) noexcept
{
  static_assert(
      std::is_floating_point_v<Source> && std::is_signed_v<Dest>,
      "float_to_int can only cast from floating point types to signed integer types");

  return static_cast<Dest>(_source);
}

}
}

#endif
