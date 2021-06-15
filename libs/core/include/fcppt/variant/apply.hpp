//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/variant/object_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <variant>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief Applies a function to the elements of several variants.
\ingroup fcpptvariant

TODO(concepts)
*/
template <typename Function, fcppt::variant::object_concept... Variants>
[[nodiscard]] inline decltype(auto) apply(Function const &_function, Variants &&..._variants)
{
  return std::visit(_function, fcppt::move_if_rvalue<Variants>(_variants.impl())...);
}

}

#endif
