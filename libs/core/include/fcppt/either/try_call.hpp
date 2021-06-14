//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_TRY_CALL_HPP_INCLUDED
#define FCPPT_EITHER_TRY_CALL_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/concepts/move_constructible.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4702)

/**
\brief Catches exceptions of a function call and puts the result in an either.

\ingroup fcppteither

Calls \a _function in a try block. If \a _function returns <code>s</code>,
then the result is success <code>s</code>.  If the function throws an
exception <code>e</code> of type \a Exception, then the result is the failure
<code>_to_exception(e)</code>.

\tparam Exception The exception type to be caught.
*/
template <
    fcppt::concepts::move_constructible Exception,
    fcppt::concepts::invocable_move Function,
    fcppt::concepts::invocable_move<Exception> ToException>
[[nodiscard]] fcppt::either::
    object<std::invoke_result_t<ToException, Exception>, std::invoke_result_t<Function>>
    try_call(Function const &_function, ToException const &_to_exception)
{
  using result_type = fcppt::either::
      object<std::invoke_result_t<ToException, Exception>, std::invoke_result_t<Function>>;

  try
  {
    return result_type{_function()};
  }
  catch (Exception const &_exception)
  {
    return result_type{_to_exception(_exception)};
  }
}

FCPPT_PP_POP_WARNING

}

#endif
