//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_TO_OPTIONAL_REF_HPP_INCLUDED
#define FCPPT_VARIANT_TO_OPTIONAL_REF_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/has_type_v.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/variant/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief Converts a variant and a type to an optional reference.

\ingroup fcpptvariant
*/
template <typename Type, fcppt::variant::object_concept Variant>
[[nodiscard]] fcppt::optional::reference<Type> to_optional_ref(Variant &_variant)
requires fcppt::variant::has_type_v<Variant,std::remove_const_t<Type>>
{
  using result_type = fcppt::optional::reference<Type>;

  using element_type = std::remove_cv_t<Type>;

  return fcppt::variant::holds_type<element_type>(_variant)
             ? result_type{fcppt::make_ref(fcppt::variant::get_unsafe<element_type>(_variant))}
             : result_type{};
}

}

#endif
