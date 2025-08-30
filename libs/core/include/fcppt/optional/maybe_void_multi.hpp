//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAYBE_VOID_MULTI_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_VOID_MULTI_HPP_INCLUDED

#include <fcppt/optional/maybe_multi.hpp>
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <concepts>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Transforms optional values or does nothing.

\ingroup fcpptoptional

A multi version of #fcppt::optional::maybe_void.
If \a _optionals are set to <code>x_1, ..., x_n</code>, then <code>_transform(x_1, ..., x_n)</code> is called.
*/
template <
    fcppt::optional::object_concept... Optionals,
    std::invocable<fcppt::optional::move_type<Optionals>...> Transform>
inline void maybe_void_multi(Transform const _transform, Optionals &&..._optionals)
{
  fcppt::optional::maybe_multi([] {}, _transform, std::forward<Optionals>(_optionals)...);
}
}

#endif
