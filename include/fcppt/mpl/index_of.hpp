//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INDEX_OF_HPP_INCLUDED
#define FCPPT_MPL_INDEX_OF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/find.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace mpl
{

/// Return the index of @a Element in @a Sequence
/**
\tparam Sequence An MPL sequence
\tparam Element The element to find
\return The index of the element
*/
template<
	typename Sequence,
	typename Element
>
struct index_of
:
boost::mpl::distance<
	typename boost::mpl::begin<
		Sequence
	>::type,
	typename boost::mpl::find<
		Sequence,
		Element
	>::type
>
{
	BOOST_STATIC_ASSERT((
		boost::mpl::contains<
			Sequence,
			Element
		>::value
	));
};

}
}

#endif
