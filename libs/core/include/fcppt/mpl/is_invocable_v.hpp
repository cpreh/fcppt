//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IS_INVOCABLE_V_HPP_INCLUDED
#define FCPPT_MPL_IS_INVOCABLE_V_HPP_INCLUDED

#include <fcppt/mpl/is_invocable.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl
{
/**
\brief Checks if a function can be invoked with a given argument list.
\ingroup fcpptmpl
\see fcppt::mpl::is_invocable
*/
template <typename F, fcppt::mpl::list::object_concept L>
constexpr inline bool is_invocable_v = fcppt::mpl::is_invocable<F,L>::value;
}

#endif
