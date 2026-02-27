//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_TYPES_OF_HPP_INCLUDED
#define FCPPT_VARIANT_TYPES_OF_HPP_INCLUDED

#include <fcppt/variant/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/variant/detail/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief The types of a variant.

\ingroup fcpptvariant
*/
template <fcppt::variant::object_concept Variant>
using types_of = fcppt::variant::detail::types_of<std::remove_cvref_t<Variant>>::type;

}

#endif
