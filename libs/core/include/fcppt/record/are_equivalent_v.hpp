//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ARE_EQUIVALENT_V_HPP_INCLUDED
#define FCPPT_RECORD_ARE_EQUIVALENT_V_HPP_INCLUDED

#include <fcppt/record/are_equivalent.hpp>

namespace fcppt::record
{
/**
\brief Tests if two records have the same element maps.

\ingroup fcpptrecord
*/
template <typename Record1, typename Record2>
// NOLINTNEXTLINE(modernize-type-traits)
inline constexpr bool are_equivalent_v = fcppt::record::are_equivalent<Record1, Record2>::value;
}

#endif
