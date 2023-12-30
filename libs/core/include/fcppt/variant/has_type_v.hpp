//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_HAS_TYPE_V_HPP_INCLUDED
#define FCPPT_VARIANT_HAS_TYPE_V_HPP_INCLUDED

#include <fcppt/variant/has_type.hpp>
#include <fcppt/variant/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::variant
{
/**
\brief Checks if a variant has a specific type.
\ingroup fcpptvariant
*/
template <fcppt::variant::object_concept Variant, typename Element>
// NOLINTNEXTLINE(modernize-type-traits)
inline constexpr bool has_type_v = fcppt::variant::has_type<Variant,Element>::value;
}

#endif
