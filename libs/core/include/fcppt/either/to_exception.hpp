//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_TO_EXCEPTION_HPP_INCLUDED
#define FCPPT_EITHER_TO_EXCEPTION_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>

namespace fcppt
{
namespace either
{
/**
\brief Returns the success value contained in an either or throws an exception

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then <code>s</code> is
returned. Otherwise, \a _either is set to failure <code>f</code> and the
result of <code>_make_exception(f)</code> is thrown as an exception.

\tparam MakeException Must be a function callable as <code>E (Either::failure)</code>
where <code>E</code> is the exception type
*/
template <typename Either, typename MakeException>
inline auto to_exception(Either &&_either, MakeException const _make_exception)
    -> decltype(fcppt::move_if_rvalue<Either>(_either.get_success_unsafe()))
{
  static_assert(
      fcppt::either::is_object<fcppt::type_traits::remove_cv_ref_t<Either>>::value,
      "Either must be an either");

  if (_either.has_success())
  {
    return fcppt::move_if_rvalue<Either>(_either.get_success_unsafe());
  }

  throw _make_exception(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()));
}

}
}

#endif
