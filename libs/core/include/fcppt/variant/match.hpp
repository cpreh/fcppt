//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_MATCH_HPP_INCLUDED
#define FCPPT_VARIANT_MATCH_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/mpl/list/index_of.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief Matches a variant with a function for each element type.

\ingroup fcpptvariant

Matches \a _variant with \a _functions. The functions must be listed in the
order the types appear in the variant.

TODO(concepts)
*/
template <
    fcppt::variant::object_concept Variant,
    typename... Functions>
inline decltype(auto) match(Variant &&_variant, Functions const &..._functions)
{
  auto const tuple(fcppt::tuple::make(_functions...));

  return fcppt::variant::apply(
      [&tuple](auto &&_arg) -> decltype(auto) {
        return fcppt::tuple::get<
            fcppt::mpl::list::index_of<
                fcppt::variant::types_of<std::remove_cvref_t<Variant>>,
                std::remove_cvref_t<decltype(_arg)>>::value>(tuple)(
            fcppt::move_if_rvalue<Variant>(_arg));
      },
      std::forward<Variant>(_variant));
}

}

#endif
