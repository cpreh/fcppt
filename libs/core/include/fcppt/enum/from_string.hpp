//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_FROM_STRING_HPP_INCLUDED
#define FCPPT_ENUM_FROM_STRING_HPP_INCLUDED

#include <fcppt/enum/from_string_impl.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief Converts a string to an enum.

\ingroup fcpptenum

Uses #fcppt::enum_::from_string_impl to convert a string to an enum.

\tparam Enum Must be an enum type
*/
template <typename Enum, typename = std::enable_if_t<fcppt::enum_::is_object<Enum>::value>>
inline fcppt::optional::object<Enum> from_string(std::string_view const &_string)
{
  return fcppt::enum_::from_string_impl<Enum>::get(_string);
}

}
}

#endif
