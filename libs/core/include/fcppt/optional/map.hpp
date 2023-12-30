//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAP_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAP_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Maps over an optional using a function.

\ingroup fcpptoptional

If \a _source is set to <code>x</code>, then
<code>fcppt::optional::make(_function(x))</code> is returned. Otherwise, the
empty optional is returned.
*/
template <
    fcppt::optional::object_concept Optional,
    fcppt::concepts::invocable_move<fcppt::optional::move_type<Optional>> Function>
[[nodiscard]] inline fcppt::optional::object<
    std::invoke_result_t<Function, fcppt::optional::move_type<Optional>>>
map(Optional &&_source, Function const &_function)
{
  return fcppt::optional::bind(
      std::forward<Optional>(_source),
      [&_function](auto &&_arg)
      { return fcppt::optional::make(_function(std::forward<decltype(_arg)>(_arg))); });
}
}

#endif
