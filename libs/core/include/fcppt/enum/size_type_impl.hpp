//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_SIZE_TYPE_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_SIZE_TYPE_IMPL_HPP_INCLUDED

#include <fcppt/cast/promote_int_type.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/size_type_impl_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Implementation of #fcppt::enum_::size_type.

\ingroup fcpptenum

\tparam Type Must be an enum type
*/
template <typename Type>
struct size_type_impl
{
  static_assert(fcppt::enum_::is_object<Type>::value, "Type must be an fcppt.enum type");

  using type = std::make_unsigned_t<fcppt::cast::promote_int_type<std::underlying_type_t<Type>>>;
};

}

#endif
