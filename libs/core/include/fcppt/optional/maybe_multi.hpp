//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAYBE_MULTI_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_MULTI_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable.hpp>
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/has_value_all.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Transforms multiple optional values or returns a default value.

\ingroup fcpptoptional

A multi version of \ref fcppt::optional::maybe.
If \a _optionals are set to <code>x_1, ..., x_n</code>, then <code>_transform(x_1, ..., x_n)</code> is returned.
Otherwise, the result of \a _default is returned.
*/
template <
    fcppt::optional::object_concept... Optionals,
    fcppt::concepts::invocable Default,
    fcppt::concepts::invocable<fcppt::optional::move_type<Optionals>...> Transform>
[[nodiscard]] std::invoke_result_t<Default>
maybe_multi(Default const _default, Transform const _transform, Optionals &&..._optionals) requires
    std::is_same_v<
        std::invoke_result_t<Default>,
        std::invoke_result_t<Transform, fcppt::optional::move_type<Optionals>...>>
{
  return fcppt::optional::detail::has_value_all(_optionals...)
             ? _transform(fcppt::move_if_rvalue<Optionals>(_optionals.get_unsafe())...)
             : _default();
}
}

#endif
