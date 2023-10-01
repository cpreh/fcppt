//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_ANY_OF_V_HPP_INCLUDED
#define FCPPT_MPL_LIST_ANY_OF_V_HPP_INCLUDED

#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list/any_of.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
/**
\brief Checks if a predicate holds for any type of a list.
\ingroup fcpptmpl
\see fcppt::mpl::list::any_of
*/
template <fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept L>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool any_of_v = fcppt::mpl::list::any_of<List,L>::value;
}

#endif
