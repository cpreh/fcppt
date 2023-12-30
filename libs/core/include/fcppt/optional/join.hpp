//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_JOIN_HPP_INCLUDED
#define FCPPT_OPTIONAL_JOIN_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/is_object_v.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/optional/value_type.hpp>

namespace fcppt::optional
{
/**
\brief Removes one layer of optionals.

\ingroup fcpptoptional

If \a _source is set to <code>optional{x}</code>, then <code>optional{x}</code> is returned.
Otherwise, the empty optional is returned.
*/
template <fcppt::optional::object_concept Optional>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
[[nodiscard]] inline fcppt::optional::value_type<Optional> join(Optional &&_source) requires
    fcppt::optional::is_object_v<fcppt::optional::value_type<Optional>>
{
  using result_type = fcppt::optional::value_type<Optional>;

  return _source.has_value() ? fcppt::move_if_rvalue<Optional>(_source.get_unsafe())
                             : result_type();
}
}

#endif
