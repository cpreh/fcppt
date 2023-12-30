//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_TO_OPTIONAL_HPP_INCLUDED
#define FCPPT_VARIANT_TO_OPTIONAL_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/has_type_v.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/variant/object_impl.hpp> // IWYU pragma: keep

namespace fcppt::variant
{
/**
\brief Converts a variant and a type to an optional.

\ingroup fcpptvariant
*/
template <typename Type, fcppt::variant::object_concept Variant>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
[[nodiscard]] fcppt::optional::object<Type> to_optional(Variant &&_variant)
requires fcppt::variant::has_type_v<Variant,Type>
{
  using result_type = fcppt::optional::object<Type>;

  return fcppt::variant::holds_type<Type>(_variant)
             ? result_type{fcppt::move_if_rvalue<Variant>(
                   fcppt::variant::get_unsafe<Type>(_variant))}
             : result_type{};
}

}

#endif
