//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STRING_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/enum/to_string_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief Converts an enum to a string.

\ingroup fcpptenum

Uses #fcppt::enum_::to_string_impl to convert an enum to a string.

\tparam Enum Must be an enum type
*/
template <typename Enum>
inline fcppt::string to_string(Enum const _enum)
{
  static_assert(std::is_enum<Enum>::value, "Enum must be an enum type");

  return fcppt::enum_::to_string_impl<Enum>::get(_enum);
}

}
}

#endif
