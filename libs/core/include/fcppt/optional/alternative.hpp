//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_ALTERNATIVE_HPP_INCLUDED
#define FCPPT_OPTIONAL_ALTERNATIVE_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Returns the first optional if it is not nothing.

\ingroup fcpptoptional

If \a _optional1 is not nothing, the result is \a _optional1, otherwise
the result of \a _optional2 is returned.
*/
template <fcppt::optional::object_concept Optional, fcppt::concepts::invocable_move<> Function>
[[nodiscard]] std::remove_cvref_t<Optional>
alternative(Optional &&_optional1, Function const &_optional2) requires
    std::is_same_v<std::remove_cvref_t<Optional>, std::invoke_result_t<Function>>
{
  return _optional1.has_value() ? std::forward<Optional>(_optional1) : _optional2();
}
}

#endif
