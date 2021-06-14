//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_LOOP_HPP_INCLUDED
#define FCPPT_EITHER_LOOP_HPP_INCLUDED

#include <fcppt/concepts/invocable.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object_v.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Loops a function returning an either.

\ingroup fcppteither

Calls \a _next repeatedly until it returns a failure, which is then returned as
the result. Each success value that is returned until then is passed to \a
_loop.
*/
template <
    fcppt::concepts::invocable_move Next,
    fcppt::concepts::invocable<fcppt::either::success_type<std::invoke_result_t<Next>>> Loop>
[[nodiscard]] fcppt::either::failure_type<std::invoke_result_t<Next>> loop(
    Next const &_next,
    Loop const &_loop) requires fcppt::either::is_object_v<std::invoke_result_t<Next>>
{
  using either_type = std::invoke_result_t<Next>;

  using failure_type = fcppt::either::failure_type<either_type>;

  using optional_failure_type = fcppt::optional::object<failure_type>;

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wmaybe-uninitialized)

  optional_failure_type error{};

  FCPPT_PP_POP_WARNING

  while (!error.has_value())
  {
    fcppt::either::match(
        _next(),
        [&error](failure_type &&_failure) { error = optional_failure_type{std::move(_failure)}; },
        [&_loop](fcppt::either::success_type<either_type> &&_success) {
          _loop(std::move(_success));
        });
  }

  return std::move(error.get_unsafe());
}
}

#endif
