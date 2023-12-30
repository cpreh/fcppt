//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_HOLDS_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_HOLDS_TYPE_HPP_INCLUDED

#include <fcppt/variant/has_type_v.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <variant>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief Checks if a type is held by a variant.

\ingroup fcpptvariant

The <em>currently held</em> type of a variant is the type passed to its
constructor or assignment operator. A type T <em>can be held</em> by a
<code>variant<Set></code> if T is a member of Set.

This function checks if \a Type is held by \a _variant.

\tparam Type The type to check for which must be a possible type for the variant.
*/
template <typename Type, typename... Elements>
[[nodiscard]] inline bool holds_type(fcppt::variant::object<Elements...> const &_variant)
requires fcppt::variant::has_type_v<fcppt::variant::object<Elements...>, Type>
{
  return std::holds_alternative<Type>(_variant.impl());
}

}

#endif
