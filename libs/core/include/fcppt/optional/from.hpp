//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_FROM_HPP_INCLUDED
#define FCPPT_OPTIONAL_FROM_HPP_INCLUDED

#include <fcppt/cond.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/optional/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Returns the value contained in an optional or a default value.

\ingroup fcpptoptional

If \a _optional is set to x, then x is returned. Otherwise, the result of \a
_default is returned.
*/
template <fcppt::optional::object_concept Optional, fcppt::concepts::invocable_move Default>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
[[nodiscard]] std::invoke_result_t<Default> from(Optional &&_optional, Default const _default)
requires std::is_same_v<std::invoke_result_t<Default>, fcppt::optional::value_type<Optional>>
{
  return fcppt::cond(
      _optional.has_value(),
      [&_optional]() -> std::invoke_result_t<Default> {
        return fcppt::move_if_rvalue<Optional>(_optional.get_unsafe());
      },
      _default);
}

}

#endif
