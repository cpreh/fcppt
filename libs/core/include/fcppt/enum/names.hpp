//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_NAMES_HPP_INCLUDED
#define FCPPT_ENUM_NAMES_HPP_INCLUDED

#include <fcppt/enum/names_array_fwd.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief The names of an enum.

\ingroup fcpptenum

\tparam Enum Must be an enum type
*/
template <typename Enum>
inline fcppt::enum_::names_array<Enum> const &names()
{
  static_assert(std::is_enum<Enum>::value, "Enum must be an enum type");

  return fcppt::enum_::names_impl<Enum>::get();
}

}
}

#endif
