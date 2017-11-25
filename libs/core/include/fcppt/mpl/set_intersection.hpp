//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_SET_INTERSECTION_HPP_INCLUDED
#define FCPPT_MPL_SET_INTERSECTION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/set/set10.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief The intersection of two sets

\ingroup fcpptmpl

The result contains every element that is both in \a Set1 and \a Set2.

\tparam Set1 Must be an MPL set
\tparam Set2 Must be an MPL set
*/
template<
	typename Set1,
	typename Set2
>
struct set_intersection
:
boost::mpl::copy_if<
	Set1,
	boost::mpl::has_key<
		Set2,
		boost::mpl::_1
	>,
	boost::mpl::inserter<
		boost::mpl::set0<>,
		boost::mpl::insert<
			boost::mpl::_1,
			boost::mpl::_2
		>
	>
>
{
};

}
}

#endif
