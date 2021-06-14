//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FAILURE_OPT_HPP_INCLUDED
#define FCPPT_EITHER_FAILURE_OPT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt::either
{
/**
\brief Returns the failure type as an optional.

\ingroup fcppteither
*/
template <fcppt::either::object_concept Either>
[[nodiscard]] fcppt::optional::object<fcppt::either::failure_type<Either>>
failure_opt(Either &&_either)
{
  return fcppt::optional::make_if(
      _either.has_failure(),
      [&_either] { return fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()); });
}
}

#endif
