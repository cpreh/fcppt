//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IS_INVOCABLE_HPP_INCLUDED
#define FCPPT_MPL_IS_INVOCABLE_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/apply.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/push_front.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
/**
\brief Checks if a function can be invoked with a given argument list.
\ingroup fcpptmpl
Checks if function <code>F</code> can be invoked with the types in <code>L</code>,
i.e. if <code>L = list::object<L_1,...,L_n></code>, then the result is
\code
std::is_invocable<F,L_1,...,L_n>
\endcode
*/
template <typename F, fcppt::mpl::list::object_concept L>
using is_invocable = fcppt::mpl::list::
    apply<fcppt::mpl::lambda<std::is_invocable>, fcppt::mpl::list::push_front<L, F>>;
}

#endif
