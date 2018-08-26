//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ARE_DISJOINT_HPP_INCLUDED
#define FCPPT_RECORD_ARE_DISJOINT_HPP_INCLUDED

#include <fcppt/brigand/set_intersection.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/set.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if two records have disjoint label sets

\ingroup fcpptrecord
*/
template<
	typename RecordL,
	typename RecordR
>
using
are_disjoint
=
std::is_same<
	fcppt::brigand::set_intersection<
		fcppt::record::label_set<
			RecordL
		>,
		fcppt::record::label_set<
			RecordR
		>
	>,
	::brigand::set<>
>;

}
}

#endif
