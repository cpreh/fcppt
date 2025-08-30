//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_MATCH_HPP_INCLUDED
#define FCPPT_EITHER_MATCH_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/failure_move_type.hpp>
#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/either/success_move_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <concepts>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Matches on the two cases of an either.

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then
<code>_success_function(s)</code> is returned. Otherwise, \a _either is set to
failure <code>f</code> and <code>_failure_function(f)</code> is returned.
*/
template <
    fcppt::either::object_concept Either,
    std::invocable<fcppt::either::failure_move_type<Either>> FailureFunction,
    std::invocable<fcppt::either::success_move_type<Either>> SuccessFunction>
[[nodiscard]] std::invoke_result_t<SuccessFunction, fcppt::either::success_move_type<Either>> match(
    Either &&_either, // NOLINT(cppcoreguidelines-missing-std-forward)
    FailureFunction const &_failure_function,
    SuccessFunction const &_success_function) requires
    std::is_same_v<
        std::invoke_result_t<SuccessFunction, fcppt::either::success_move_type<Either>>,
        std::invoke_result_t<FailureFunction, fcppt::either::failure_move_type<Either>>>
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

  return _either.has_success()
             ? _success_function(fcppt::move_if_rvalue<Either>(_either.get_success_unsafe()))
             : _failure_function(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()));

  FCPPT_PP_POP_WARNING
}
}

#endif
