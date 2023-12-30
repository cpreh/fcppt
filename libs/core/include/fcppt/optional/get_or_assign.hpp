//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_GET_OR_ASSIGN_HPP_INCLUDED
#define FCPPT_OPTIONAL_GET_OR_ASSIGN_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Assigns an optional if it is empty. Returns a reference to the optional's contents.

\ingroup fcpptoptional

Assigns the result of \a _function to \a _optional if \a _optional is empty and returns a reference to the contents of \a _optional.
*/
template <typename Element, fcppt::concepts::invocable_move<> Function>
[[nodiscard]] inline Element &get_or_assign(
    fcppt::optional::object<Element> &_optional,
    Function const &_function) requires std::is_same_v<std::invoke_result_t<Function>, Element>
{
  if (!_optional.has_value())
  {
    _optional = fcppt::optional::object<Element>{_function()};
  }

  return _optional.get_unsafe();
}
}

#endif
