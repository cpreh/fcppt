//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_MIN_VALUE_HPP_INCLUDED
#define FCPPT_ENUM_MIN_VALUE_HPP_INCLUDED

#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief The minimum enumerator in an enum

\ingroup fcpptenum

\tparam Type Must be an enum type
*/
template <typename Type, typename = std::enable_if_t<fcppt::enum_::is_object<Type>::value>>
using min_value = std::integral_constant<Type, fcppt::cast::int_to_enum<Type>(0)>;

}
}

#endif
