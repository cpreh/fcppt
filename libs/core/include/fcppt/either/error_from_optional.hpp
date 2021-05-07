//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_ERROR_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_EITHER_ERROR_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace either
{
/**
\brief Converts an optional error to an either.

\ingroup fcppteither

If \a _optional is set to <code>x</code>, then <code>x</code> is returned as
the failure value.
*/
template <typename Optional>
fcppt::either::error<fcppt::optional::value_type<std::remove_cvref_t<Optional>>>
error_from_optional(Optional &&_optional)
{
  static_assert(fcppt::optional::detail::check<Optional>::value, "Optional must be an optional");

  using result_type = fcppt::either::error<
      fcppt::optional::value_type<std::remove_cvref_t<Optional>>>;

  return fcppt::optional::maybe(
      std::forward<Optional>(_optional),
      [] { return result_type{fcppt::either::no_error{}}; },
      [](auto &&_value) { return result_type(fcppt::move_if_rvalue<Optional>(_value)); });
}

}
}

#endif
