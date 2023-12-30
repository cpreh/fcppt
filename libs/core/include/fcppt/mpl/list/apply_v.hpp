//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_APPLY_V_HPP_INCLUDED
#define FCPPT_MPL_LIST_APPLY_V_HPP_INCLUDED

#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/apply.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl::list
{
/**
\brief Calls a lambda using a list of arguments.
\ingroup fcpptmpl
\see fcppt::mpl::list::apply
*/
template<fcppt::mpl::lambda_concept L, fcppt::mpl::list::object_concept Args>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool apply_v = fcppt::mpl::list::apply<L,Args>::value;
}

#endif
