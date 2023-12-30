//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ALL_DISJOINT_V_HPP_INCLUDED
#define FCPPT_RECORD_ALL_DISJOINT_V_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/record/all_disjoint.hpp>

namespace fcppt::record
{
/**
\brief Tests if multiple records have disjoint label sets.
\ingroup fcpptrecord
\see fcppt::record::all_disjoint
*/
template <fcppt::mpl::list::object_concept Records>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool all_disjoint_v = fcppt::record::all_disjoint<Records>::value;
}

#endif
