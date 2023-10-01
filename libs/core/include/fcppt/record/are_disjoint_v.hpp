//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ARE_DISJOINT_V_HPP_INCLUDED
#define FCPPT_RECORD_ARE_DISJOINT_V_HPP_INCLUDED

#include <fcppt/record/are_disjoint.hpp>

namespace fcppt::record
{
/**
\brief Tests if two records have disjoint label sets.
\ingroup fcpptrecord
\see fcppt::record::are_disjoint
*/
template <typename RecordL, typename RecordR>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool are_disjoint_v = fcppt::record::are_disjoint<RecordL, RecordR>::value;
}

#endif
