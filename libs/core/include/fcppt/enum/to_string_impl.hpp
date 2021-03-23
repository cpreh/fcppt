//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STRING_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/enum/names.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief Customization point to convert an enum to a string.

\ingroup fcpptenum

The default implementation uses #fcppt::enum_::names.

\tparam Enum Must be an enum type
*/
template <typename Enum, typename Enable>
struct to_string_impl
{
  static_assert(std::is_enum<Enum>::value, "Enum must be an enum type");

  static fcppt::string get(Enum const _enum) { return fcppt::enum_::names<Enum>()[_enum]; }
};

}
}

#endif
