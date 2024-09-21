//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED
#define FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep

namespace fcppt::optional
{
/**
\brief Returns the value contained in an optional or throws an exception.

\ingroup fcpptoptional

If \a _optional is set to x, then x is returned. Otherwise, the result of \a
_make_exception is thrown as an exception.
*/
template <fcppt::optional::object_concept Optional, fcppt::concepts::invocable_move MakeException>
[[nodiscard]] inline fcppt::optional::move_type<Optional>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
to_exception(Optional &&_optional, MakeException const &_make_exception)
{
  if (_optional.has_value())
  {
    return fcppt::move_if_rvalue<Optional>(_optional.get_unsafe());
  }

  throw _make_exception();
}
}

#endif
