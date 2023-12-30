//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_SEQUENCE_ERROR_HPP_INCLUDED
#define FCPPT_EITHER_SEQUENCE_ERROR_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Folds over a range, breaking out on the first error.

\ingroup fcppteither

This function is similar to #fcppt::either::sequence, except it
does not produce an output sequence. Instead, \a _function returns #fcppt::either::error,
which on success contains an #fcppt::unit.
Let <code>_sequence = [x_1, ..., x_n]</code>.
The algorithms calls <code>_function(x_1), ..., _function(x_i)</code>,
where <code>_function(x_i)</code> is either the first call that returns a failure, in
which case the failure is returned as the result, or <code>i=n</code>, in which case
success is returned.

\tparam Sequence Must be a range.

TODO(concepts)
*/
template <
    typename Sequence,
    fcppt::concepts::invocable_move<
        fcppt::container::to_value_type<std::remove_reference_t<Sequence>>> Function>
[[nodiscard]] std::
    invoke_result_t<Function, fcppt::container::to_value_type<std::remove_reference_t<Sequence>>>
    sequence_error(Sequence &&_sequence, Function const &_function) requires
    fcppt::either::is_object_v<std::invoke_result_t<
        Function,
        fcppt::container::to_value_type<std::remove_reference_t<Sequence>>>> &&
    std::is_same_v<
        fcppt::either::success_type<std::invoke_result_t<
            Function,
            fcppt::container::to_value_type<std::remove_reference_t<Sequence>>>>,
        fcppt::either::no_error>
{
  using either_type = std::
      invoke_result_t<Function, fcppt::container::to_value_type<std::remove_reference_t<Sequence>>>;

  return fcppt::algorithm::fold_break(
      std::forward<Sequence>(_sequence),
      either_type{fcppt::either::no_error{}},
      [&_function](auto &&_element, either_type)
      {
        using inner_type = either_type;
        return fcppt::either::match(
            _function(fcppt::move_if_rvalue<Sequence>(_element)),
            [](fcppt::either::failure_type<inner_type> &&_error)
            { return std::make_pair(fcppt::loop::break_, inner_type{std::move(_error)}); },
            [](fcppt::either::no_error) {
              return std::make_pair(fcppt::loop::continue_, inner_type{fcppt::either::no_error{}});
            });
      });
}
}

#endif
