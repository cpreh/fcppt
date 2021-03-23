//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_CONSTRUCT_HPP_INCLUDED
#define FCPPT_EITHER_CONSTRUCT_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace either
{
/**
\brief Constructs an either by calling one of two functions

\ingroup fcppteither

If \a _value is true then <code>_success()</code> is returned.
Otherwise, <code>_failure()</code> is returned.
*/
template <typename Failure, typename Success>
fcppt::either::object<std::result_of_t<Failure()>, std::result_of_t<Success()>>
construct(bool const _value, Success const &_success, Failure const &_failure)
{
  using result_type =
      fcppt::either::object<std::result_of_t<Failure()>, std::result_of_t<Success()>>;

  return _value ? result_type{_success()} : result_type{_failure()};
}

}
}

#endif
