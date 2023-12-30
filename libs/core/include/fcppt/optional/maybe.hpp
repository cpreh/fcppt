//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAYBE_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_HPP_INCLUDED

#include <fcppt/cond.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable.hpp> // IWYU pragma: keep
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Transforms an optional value or returns a default value.

\ingroup fcpptoptional

For the lack of a better name, this function is called maybe like in Haskell.
If \a _optional is set to x, then <code>_transform(x)</code> is returned.
Otherwise, the result of \a _default is returned.
*/
template <
    fcppt::optional::object_concept Optional,
    fcppt::concepts::invocable Default,
    fcppt::concepts::invocable<fcppt::optional::move_type<Optional>> Transform>
[[nodiscard]] std::invoke_result_t<Default>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
maybe(Optional &&_optional, Default const &_default, Transform const &_transform) requires
    std::is_same_v<
        std::invoke_result_t<Default>,
        std::invoke_result_t<Transform, fcppt::optional::move_type<Optional>>>
{
  return fcppt::cond(
      _optional.has_value(),
      [&_transform, &_optional]() -> std::invoke_result_t<Default> {
        return _transform(fcppt::move_if_rvalue<Optional>(_optional.get_unsafe()));
      },
      _default);
}
}

#endif
