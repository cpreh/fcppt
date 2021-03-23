//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_TO_CONTAINER_HPP_INCLUDED
#define FCPPT_OPTIONAL_TO_CONTAINER_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace optional
{
/**
\brief Puts the value of an optional into a container or returns an empty container.

\ingroup fcpptoptional

If \a _source holds <code>x</code>, then <code>Container{x}</code> is returned.
Otherwise the empty container is returned.

\a Container and \a Optional must have the same value types.
*/
template <typename Container, typename Optional>
Container to_container(Optional &&_source)
{
  static_assert(fcppt::optional::detail::check<Optional>::value, "Optional must be an optional");

  static_assert(
      std::is_same<
          fcppt::type_traits::value_type<Container>,
          fcppt::optional::value_type<fcppt::type_traits::remove_cv_ref_t<Optional>>>::value,
      "Container must have the same value_type as Optional");

  return fcppt::optional::maybe(
      std::forward<Optional>(_source),
      [] { return Container{}; },
      [](auto &&_inner) {
        return fcppt::container::make<Container>(fcppt::move_if_rvalue<Optional>(_inner));
      });
}

}
}

#endif
