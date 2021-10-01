//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_TO_UNSIGNED_HPP_INCLUDED
#define FCPPT_CAST_TO_UNSIGNED_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Converts a signed int to its unsigned type

\ingroup fcpptcasts

Converts \a _value to its unsigned type. This cast is unsafe and should only be
used if \a _value is positive.

\tparam Type Must be a signed type
*/
template <typename Type>
inline constexpr std::make_unsigned_t<Type> to_unsigned(Type const _value) noexcept
{
  static_assert(std::is_signed<Type>::value, "to_unsigned can only cast from signed types");

  return static_cast<std::make_unsigned_t<Type>>(_value);
}

}

#endif
