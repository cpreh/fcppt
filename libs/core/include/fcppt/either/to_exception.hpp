//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_TO_EXCEPTION_HPP_INCLUDED
#define FCPPT_EITHER_TO_EXCEPTION_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/either/failure_move_type.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_move_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Returns the success value contained in an either or throws an exception.

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then <code>s</code> is
returned. Otherwise, \a _either is set to failure <code>f</code> and the
result of <code>_make_exception(f)</code> is thrown as an exception.
*/
template <
    fcppt::either::object_concept Either,
    fcppt::concepts::invocable_move<fcppt::either::failure_move_type<Either>> MakeException>
[[nodiscard]] inline fcppt::either::success_move_type<Either>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
to_exception(Either &&_either, MakeException const _make_exception)
{
  if (_either.has_success())
  {
    return fcppt::move_if_rvalue<Either>(_either.get_success_unsafe());
  }

  throw _make_exception(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()));
}
}

#endif
