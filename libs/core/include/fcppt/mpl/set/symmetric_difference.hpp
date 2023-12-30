//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
#define FCPPT_MPL_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED

#include <fcppt/mpl/set/difference.hpp>
#include <fcppt/mpl/set/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/set/union.hpp>

namespace fcppt::mpl::set
{
/**
\brief The symmetric difference of two sets.
\ingroup fcpptmpl
The result contains every element that is either in \a Set1 or in \a Set2, but
not in both.
*/
template <fcppt::mpl::set::object_concept Set1, fcppt::mpl::set::object_concept Set2>
using symmetric_difference = fcppt::mpl::set::
    union_<fcppt::mpl::set::difference<Set1, Set2>, fcppt::mpl::set::difference<Set2, Set1>>;
}

#endif
