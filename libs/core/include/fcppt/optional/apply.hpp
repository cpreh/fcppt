//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_APPLY_HPP_INCLUDED
#define FCPPT_OPTIONAL_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/concepts/invocable_move.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/reference_type.hpp>
#include <fcppt/optional/detail/has_value_all.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Applies a function to multiple optionals if each of them contains a value.

\ingroup fcpptoptional

If \a _optionals, <code>o_1,...,o_n</code> are set to <code>x_1,...,x_n</code>,
then <code>optional::object{_function(x_1,...,x_n)}</code> is returned. Otherwise, the empty
optional is returned.
*/
template <
    fcppt::optional::object_concept... Optionals,
    fcppt::concepts::invocable_move<
        fcppt::move_if_rvalue_type<Optionals, fcppt::optional::reference_type<Optionals>>...>
        Function>
[[nodiscard]] inline fcppt::optional::object<std::invoke_result_t<
    Function,
    fcppt::move_if_rvalue_type<Optionals, fcppt::optional::reference_type<Optionals>>...>>
apply(Function const &_function, Optionals &&..._optionals)
{
  return fcppt::optional::make_if(
      fcppt::optional::detail::has_value_all(_optionals...),
      [&_function, &_optionals...]
      { return _function(fcppt::move_if_rvalue<Optionals>(_optionals.get_unsafe())...); });
}
}

#endif
