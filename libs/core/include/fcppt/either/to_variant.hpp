//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_TO_VARIANT_HPP_INCLUDED
#define FCPPT_EITHER_TO_VARIANT_HPP_INCLUDED

#include <fcppt/either/match.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/variant_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Converts an either into a variant.
\ingroup fcppteither
*/
template <fcppt::either::object_concept Either>
[[nodiscard]]
fcppt::either::variant_type<std::remove_cvref_t<Either>>
to_variant(Either &&_source)
{
  auto const make_variant{[](auto &&_inner)
                          {
                            return fcppt::either::variant_type<std::remove_cvref_t<Either>>{
                                std::forward<decltype(_inner)>(_inner)};
                          }};

  return fcppt::either::match(
      std::forward<Either>(_source),
      make_variant,
      make_variant);
}
}

#endif
