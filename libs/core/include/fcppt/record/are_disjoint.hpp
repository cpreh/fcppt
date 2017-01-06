//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ARE_DISJOINT_HPP_INCLUDED
#define FCPPT_RECORD_ARE_DISJOINT_HPP_INCLUDED

#include <fcppt/mpl/set_intersection.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/empty.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if two records have disjoint label sets
*/
template<
	typename RecordL,
	typename RecordR
>
using
are_disjoint
=
boost::mpl::empty<
	typename
	fcppt::mpl::set_intersection<
		fcppt::record::label_set<
			RecordL
		>,
		fcppt::record::label_set<
			RecordR
		>
	>::type
>;

}
}

#endif
