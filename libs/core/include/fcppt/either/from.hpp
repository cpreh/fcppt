//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FROM_HPP_INCLUDED
#define FCPPT_EITHER_FROM_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/failure_move_type.hpp>
#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/either/success_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <concepts>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Transforms the failure type of an either into a success type.

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then
<code>s</code> is returned. Otherwise, \a _either is set to
failure <code>f</code> and <code>_failure_function(f)</code> is returned.
*/
template <
    fcppt::either::object_concept Either,
    std::invocable<fcppt::either::failure_move_type<Either>> FailureFunction>
[[nodiscard]] fcppt::either::success_type<Either> from(
    Either &&_either, // NOLINT(cppcoreguidelines-missing-std-forward)
    FailureFunction const &_failure_function)
  requires std::is_same_v<
      std::invoke_result_t<FailureFunction, fcppt::either::failure_move_type<Either>>,
      fcppt::either::success_type<Either>>
{
  return _either.has_success()
             ? fcppt::move_if_rvalue<Either>(_either.get_success_unsafe())
             : _failure_function(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()));
}
}

#endif
