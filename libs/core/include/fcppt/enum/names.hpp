//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_NAMES_HPP_INCLUDED
#define FCPPT_ENUM_NAMES_HPP_INCLUDED

#include <fcppt/enum/array_init.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief The names of an enum type.

\ingroup fcpptenum

\tparam Enum Must be an enum type
*/
template <typename Enum, typename = std::enable_if_t<fcppt::enum_::is_object<Enum>::value>>
inline fcppt::enum_::names_array<Enum> names()
{
  return fcppt::enum_::array_init<fcppt::enum_::names_array<Enum>>(
      []<Enum Index>(std::integral_constant<Enum, Index>)
      { return fcppt::enum_::to_string(Index); });
}

}
}

#endif
