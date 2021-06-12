//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_FILTER_HPP_INCLUDED
#define FCPPT_OPTIONAL_FILTER_HPP_INCLUDED

#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Filters an optional

\ingroup fcpptoptional

If \a _source is set to <code>x</code> and <code>_function(x)</code> returns
true, \a _source is returned. Otherwise, the empty optional is returned.
*/
template <
    fcppt::optional::object_concept Optional,
    fcppt::concepts::invocable_move<fcppt::optional::value_type<Optional>> Function>
[[nodiscard]] std::remove_cvref_t<Optional>
filter(Optional &&_source, Function const &_function) requires
    std::is_same_v<bool, std::invoke_result_t<Function, fcppt::optional::value_type<Optional>>>
{
  return _source.has_value() && _function(_source.get_unsafe()) ? std::forward<Optional>(_source)
                                                                : std::remove_cvref_t<Optional>{};
}
}

#endif
