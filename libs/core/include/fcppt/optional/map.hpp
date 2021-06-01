//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAP_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace optional
{
/**
\brief Maps over an optional using a function.

\ingroup fcpptoptional

If \a _source is set to <code>x</code>, then
<code>optional(_function(x))</code> is returned. Otherwise, the empty optional
is returned.
*/
template <
    fcppt::optional::object_concept Optional,
    fcppt::concepts::invocable_move<
        fcppt::move_if_rvalue_type<Optional, fcppt::optional::value_type<Optional>>> Function>
inline fcppt::optional::object<std::invoke_result_t<
    Function,
    fcppt::move_if_rvalue_type<Optional, fcppt::optional::value_type<Optional>>>>
map(Optional &&_source, Function const &_function)
{
  using arg_type = decltype(fcppt::move_if_rvalue<Optional>(_source.get_unsafe()));

  using result_type = fcppt::optional::object<std::invoke_result_t<Function, arg_type>>;

  return fcppt::optional::bind(
      std::forward<Optional>(_source),
      [&_function](arg_type _arg) { return result_type(_function(std::forward<arg_type>(_arg))); });
}
}
}

#endif
