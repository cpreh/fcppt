//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_MAP_FAILURE_HPP_INCLUDED
#define FCPPT_EITHER_MAP_FAILURE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/either/failure_move_type.hpp>
#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Maps over the failure type of an either.

\ingroup fcppteither

If \a _either is set to failure <code>f</code>, <code>r = _function(f)</code>
is called and the result is
<code>either<decltype(r),Either::success>(r)</code>.  Otherwise, the success in
\a _either is returned.
*/
template <
    fcppt::either::object_concept Either,
    fcppt::concepts::invocable_move<fcppt::either::failure_move_type<Either>> Function>
fcppt::either::object<
    std::invoke_result_t<Function, fcppt::either::failure_move_type<Either>>,
    fcppt::either::success_type<Either>>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
map_failure(Either &&_either, Function const &_function)
{
  using result_type = fcppt::either::object<
      std::invoke_result_t<Function, fcppt::either::failure_move_type<Either>>,
      fcppt::either::success_type<Either>>;

  return _either.has_failure()
             ? result_type(_function(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe())))
             : result_type(fcppt::move_if_rvalue<Either>(_either.get_success_unsafe()));
}
}

#endif
