//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_RETURN_IF_HPP_INCLUDED
#define FCPPT_OPTIONAL_RETURN_IF_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/optional/is_object_v.hpp>
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Forwards an optional depending on a boolean.

\ingroup fcpptoptional

If \a _is_set is true, then <code>_function()</code> is returned.
Otherwise, the empty optional is returned.
*/
template <fcppt::concepts::invocable_move Function>
[[nodiscard]] inline std::invoke_result_t<Function>
return_if(bool const _is_set, Function const &_function)
  requires fcppt::optional::is_object_v<std::invoke_result_t<Function>>
{
  using result_type = std::invoke_result_t<Function>;

  // TODO(philipp): This is technically a valid warning depending on the function.
  // NOLINTNEXTLINE(clang-analyzer-core.StackAddressEscape)
  return _is_set ? _function() : result_type{};
}
}

#endif
