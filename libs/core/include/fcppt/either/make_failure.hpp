//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_MAKE_FAILURE_HPP_INCLUDED
#define FCPPT_EITHER_MAKE_FAILURE_HPP_INCLUDED

#include <fcppt/concepts/move_constructible.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Create an either with a failure.

\ingroup fcppteither

\tparam Success The success type of the either.
*/
template <fcppt::concepts::move_constructible Success, typename Failure>
[[nodiscard]] inline fcppt::either::object<std::remove_cvref_t<Failure>, Success>
make_failure(Failure &&_failure)
{
  return fcppt::either::object<std::remove_cvref_t<Failure>, Success>{
      std::forward<Failure>(_failure)};
}
}

#endif
