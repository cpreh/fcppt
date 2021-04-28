//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STRING_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_HPP_INCLUDED

#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
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
template <typename Enum, typename = std::enable_if<fcppt::enum_::is_object<Enum>::value>>
inline std::string_view to_string(Enum const _enum)
{
  return fcppt::enum_::to_string_impl<Enum>::get(_enum);
}

}
}

#endif
