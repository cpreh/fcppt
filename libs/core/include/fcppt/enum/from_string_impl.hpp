//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_FROM_STRING_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_FROM_STRING_IMPL_HPP_INCLUDED

#include <fcppt/enum/from_string_impl_fwd.hpp> // IWYU pragma: keep
#include <fcppt/enum/index_of_array.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/names.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Customization point to convert a string to an enum.

\ingroup fcpptenum

The default implementation iterates over all outputs of #fcppt::enum_::to_string.

\tparam Enum Must be an enum type
*/
template <typename Enum, typename Enable>
struct from_string_impl
{
  static_assert(fcppt::enum_::is_object<Enum>::value, "Enum must be an enum type");

  static fcppt::optional::object<Enum> get(std::string_view const _string)
  {
    return fcppt::enum_::index_of_array(fcppt::enum_::names<Enum>(), _string);
  }
};

}

#endif
