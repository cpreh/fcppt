//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FAILURE_OPT_HPP_INCLUDED
#define FCPPT_EITHER_FAILURE_OPT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace either
{
/**
\brief Returns the failure type as an optional

\ingroup fcppteither
*/
template <typename Either>
fcppt::optional::object<fcppt::either::failure_type<std::remove_cvref_t<Either>>>
failure_opt(Either &&_either)
{
  using either = std::remove_cvref_t<Either>;

  static_assert(fcppt::either::is_object<either>::value, "Either must be an either");

  using result_type = fcppt::optional::object<fcppt::either::failure_type<either>>;

  return _either.has_failure()
             ? result_type(fcppt::move_if_rvalue<Either>(_either.get_failure_unsafe()))
             : result_type();
}

}
}

#endif
