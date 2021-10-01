//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_ENUM_TO_UNDERLYING_HPP_INCLUDED
#define FCPPT_CAST_ENUM_TO_UNDERLYING_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Converts an enum to its underlying type

\ingroup fcpptcasts

Converts \a _enum to its underlying integer type. This cast is safe.

\tparam Enum Must be an enumeration type
*/
template <typename Enum, typename = std::enable_if<std::is_enum_v<Enum>>>
inline constexpr std::underlying_type_t<Enum> enum_to_underlying(Enum const _enum) noexcept
{
  return static_cast<std::underlying_type_t<Enum>>(_enum);
}

}

#endif
