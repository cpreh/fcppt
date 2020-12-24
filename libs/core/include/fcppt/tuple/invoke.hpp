//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_INVOKE_HPP_INCLUDED
#define FCPPT_TUPLE_INVOKE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/metal/is_invocable.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/types_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
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
        fcppt::tuple::is_object<fcppt::type_traits::remove_cv_ref_t<Tuple>>,
        fcppt::metal::
            is_invocable<F, fcppt::tuple::types_of<fcppt::type_traits::remove_cv_ref_t<Tuple>>>>>>
[[nodiscard]] inline constexpr decltype(auto) invoke(F const &_f, Tuple &&_tuple)
{
  return std::apply(_f, fcppt::move_if_rvalue<Tuple>(_tuple.impl()));
}
}

#endif
