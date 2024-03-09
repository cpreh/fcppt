//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_FROM_INT_HPP_INCLUDED
#define FCPPT_ENUM_FROM_INT_HPP_INCLUDED

#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Cast an unsigned value to an enum

\ingroup fcpptenum

Casts the unsigned value \a _value to \a Enum. Returns an empty optional if the
cast fails.

\param _value The value to cast from

\tparam Enum Must be an enum type

\tparam Value Must be an unsigned type
*/
template <typename Enum, typename Value>
fcppt::optional::object<Enum> from_int(Value const &_value) noexcept
  requires(std::is_unsigned_v<Value> && fcppt::enum_::is_object<Enum>::value)
{
  return fcppt::optional::make_if(
      fcppt::cast::size<fcppt::enum_::size_type<Enum>>(_value) < fcppt::enum_::size<Enum>::value,
      [&_value] { return fcppt::cast::int_to_enum<Enum>(_value); });
}
}

#endif
