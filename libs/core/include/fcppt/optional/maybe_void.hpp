//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAYBE_VOID_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_VOID_HPP_INCLUDED

#include <fcppt/concepts/invocable.hpp>
#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/reference_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Transforms an optional value or does nothing.

\ingroup fcpptoptional

If \a _optional is set to x, then <code>_transform(x)</code> is called.
*/
template <
    fcppt::optional::object_concept Optional,
    fcppt::concepts::invocable<
        fcppt::move_if_rvalue_type<Optional, fcppt::optional::reference_type<Optional>>> Transform>
inline void maybe_void(Optional &&_optional, Transform const &_transform)
{
  fcppt::optional::maybe(
      std::forward<Optional>(_optional), [] {}, _transform);
}

}

#endif
