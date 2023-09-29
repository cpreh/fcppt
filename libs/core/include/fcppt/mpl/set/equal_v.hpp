//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_EQUAL_V_HPP_INCLUDED
#define FCPPT_MPL_SET_EQUAL_V_HPP_INCLUDED

#include <fcppt/mpl/set/equal.hpp>
#include <fcppt/mpl/set/object_concept.hpp>

namespace fcppt::mpl::set
{
/**
\brief Checks if two sets are equal.
\ingroup fcpptmpl
\see fcppt::mpl::set::equal
*/
template <fcppt::mpl::set::object_concept Set1, fcppt::mpl::set::object_concept Set2>
constexpr inline bool equal_v = fcppt::mpl::set::equal<Set1,Set2>::value;
}

#endif
