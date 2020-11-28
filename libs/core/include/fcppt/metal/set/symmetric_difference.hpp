//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
#define FCPPT_METAL_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED

#include <fcppt/metal/set/difference.hpp>
#include <fcppt/metal/set/union.hpp>

namespace fcppt
{
namespace metal
{
namespace set
{
/**
\brief The symmetric difference of two sets.

\ingroup fcpptmetal

The result contains every element that is either in \a Set1 or in \a Set2, but
not in both.

\tparam Set1 Must be a metal set.
\tparam Set2 Must be a metal set.
*/
template <typename Set1, typename Set2>
using symmetric_difference = fcppt::metal::set::
    union_<fcppt::metal::set::difference<Set1, Set2>, fcppt::metal::set::difference<Set2, Set1>>;

}
}
}

#endif
