//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_BIND_HPP_INCLUDED
#define FCPPT_OPTIONAL_BIND_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/optional/is_object.hpp> // IWYU pragma: keep
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Converts an optional of one type to another.

\ingroup fcpptoptional

If \a _source is set to <code>x</code>, then <code>_function(x)</code> is returned.
Otherwise, the empty optional is returned.
*/
template <
    fcppt::optional::object_concept Optional,
    fcppt::concepts::invocable_move<fcppt::optional::move_type<Optional>> Function>
[[nodiscard]] inline std::invoke_result_t<Function, fcppt::optional::move_type<Optional>>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
bind(Optional &&_source, Function const &_function) requires fcppt::optional::is_object_v<
    std::invoke_result_t<Function, fcppt::optional::move_type<Optional>>>
{
  using result_type = std::invoke_result_t<Function, fcppt::optional::move_type<Optional>>;
  return _source.has_value() ? _function(fcppt::move_if_rvalue<Optional>(_source.get_unsafe()))
                             : result_type{};
}
}

#endif
