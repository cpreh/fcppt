//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_INVOKE_HPP_INCLUDED
#define FCPPT_TUPLE_INVOKE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/mpl/is_invocable.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Calls a function with the elements of a tuple.
\ingroup fcppttuple

This is the same as <code>std::apply</code>.  Let <code>_tuple =
(x_1,...,x_n)</code>. Then the result is <code>f(x_1,...,x_n)</code>.
*/
template <
    typename F,
    typename Tuple,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::tuple::is_object<std::remove_cvref_t<Tuple>>,
        fcppt::mpl::is_invocable<F, fcppt::tuple::types_of<std::remove_cvref_t<Tuple>>>>>>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
[[nodiscard]] inline constexpr decltype(auto) invoke(F const &_f, Tuple &&_tuple)
{
  return std::apply(_f, fcppt::move_if_rvalue<Tuple>(_tuple.impl()));
}
}

#endif
