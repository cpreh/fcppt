//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_MAP_HPP_INCLUDED
#define FCPPT_EITHER_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_move_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Maps over the success type of an either.

\ingroup fcppteither

If \a _either is set to success <code>s</code>, <code>r = _function(s)</code>
is called and the result is
<code>either<Either::failure,decltype(r)>(r)</code>. Otherwise, the failure in
\a _either is returned.
*/
template <
    fcppt::either::object_concept Either,
    fcppt::concepts::invocable_move<fcppt::either::success_move_type<Either>> Function>
[[nodiscard]] fcppt::either::object<
    fcppt::either::failure_type<Either>,
    std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>>
map(Either &&_either, Function const &_function)
{
  using result_type = fcppt::either::object<
      fcppt::either::failure_type<Either>,
      std::invoke_result_t<Function, fcppt::either::success_move_type<Either>>>;

  return _either.has_success()
             ? result_type(_function(fcppt::move_if_rvalue<Either>(_either.get_success_unsafe())))
             : result_type(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()));
}
}

#endif
