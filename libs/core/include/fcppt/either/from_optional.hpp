//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_EITHER_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Converts an optional to an either

\ingroup fcppteither

If \a _optional is set to <code>x</code>, then <code>x</code> is returned as
the success value, otherwise <code>_failure_function()</code> is returned as
the failure value.

\tparam FailureFunction Must be a function callable as <code>R ()</code> where
<code>R</code> is the failure type
*/
template <fcppt::optional::object_concept Optional, fcppt::concepts::invocable_move FailureFunction>
[[nodiscard]] fcppt::either::
    object<std::invoke_result_t<FailureFunction>, fcppt::optional::value_type<Optional>>
    from_optional(Optional &&_optional, FailureFunction const &_failure_function)
{
  using result_type = fcppt::either::
      object<std::invoke_result_t<FailureFunction>, fcppt::optional::value_type<Optional>>;

  return fcppt::optional::maybe(
      std::forward<Optional>(_optional),
      [&_failure_function] { return result_type(_failure_function()); },
      [](auto &&_value) { return result_type(fcppt::move_if_rvalue<Optional>(_value)); });
}
}

#endif
