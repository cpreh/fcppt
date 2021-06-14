//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_BIND_HPP_INCLUDED
#define FCPPT_EITHER_BIND_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object_v.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_move_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Monadic bind on the success type of an either.

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then <code>_function(s)</code>
is returned. Otherwise, the failure in \a _either is returned.
*/
template <
    fcppt::either::object_concept Either,
    fcppt::concepts::invocable_move<fcppt::either::success_move_type<Either>> Function>
[[nodiscard]] std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>
bind(Either &&_either, Function const &_function) requires fcppt::either::is_object_v<
    std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>> &&
    std::is_same_v<
        fcppt::either::failure_type<Either>,
        fcppt::either::failure_type<
            std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>>>
{
  using result_type = std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>;

  return _either.has_success()
             ? _function(fcppt::move_if_rvalue<Either>(_either.get_success_unsafe()))
             : result_type{_either.get_failure_unsafe()};
}
}

#endif
