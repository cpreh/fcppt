//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_COMBINE_HPP_INCLUDED
#define FCPPT_OPTIONAL_COMBINE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/move_type.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Combines two optionals

\ingroup fcpptoptional

If \a _optional1 is set to x1 and \a _optional2 is set to x2, then the result is
<code>Optional(_function(x1, x2))</code>. Otherwise, if at least one optional
is set, that optional is returned.
*/
template <
    fcppt::optional::object_concept Optional1,
    fcppt::optional::object_concept Optional2,
    fcppt::concepts::invocable_move<
        fcppt::optional::move_type<Optional1>,
        fcppt::optional::move_type<Optional2>> Function>
[[nodiscard]] fcppt::optional::object<fcppt::optional::value_type<Optional1>>
combine(Optional1 &&_optional1, Optional2 &&_optional2, Function const &_function) requires std::
    is_same_v<fcppt::optional::value_type<Optional1>, fcppt::optional::value_type<Optional2>> &&
    std::is_same_v<
        fcppt::optional::value_type<Optional1>,
        std::invoke_result_t<
            Function,
            fcppt::optional::move_type<Optional1>,
            fcppt::optional::move_type<Optional2>>>
{
  if (!_optional1.has_value())
  {
    return std::forward<Optional2>(_optional2);
  }

  if (!_optional2.has_value())
  {
    return std::forward<Optional1>(_optional1);
  }

  return fcppt::optional::make(_function(
      fcppt::move_if_rvalue<Optional1>(_optional1.get_unsafe()),
      fcppt::move_if_rvalue<Optional2>(_optional2.get_unsafe())));
}
}

#endif
