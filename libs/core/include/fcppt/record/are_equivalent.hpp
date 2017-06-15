//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED
#define FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED

#include <fcppt/mpl/all_of.hpp>
#include <fcppt/mpl/set_symmetric_difference.hpp>
#include <fcppt/record/element_map.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/placeholders.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if two records have the same element maps

\ingroup fcpptrecord
*/
template<
	typename Record1,
	typename Record2
>
using
are_equivalent
=
boost::mpl::and_<
	boost::mpl::empty<
		typename
		fcppt::mpl::set_symmetric_difference<
			fcppt::record::label_set<
				Record1
			>,
			fcppt::record::label_set<
				Record2
			>
		>::type
	>,
	typename
	fcppt::mpl::all_of<
		fcppt::record::label_set<
			Record1
		>,
		std::is_same<
			boost::mpl::at<
				fcppt::record::element_map<
					Record1
				>,
				boost::mpl::_1
			>,
			boost::mpl::at<
				fcppt::record::element_map<
					Record2
				>,
				boost::mpl::_1
			>
		>
	>::type
>;

}
}

#endif
