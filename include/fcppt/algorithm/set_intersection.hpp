//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SET_INTERSECTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_SET_INTERSECTION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Calculates the intersection of two sets

This just calls <code>std::set_intersection</code> and writes the result to a
new container.

\ingroup fcpptalgorithm

\tparam Set Must be default-constructible
*/
template<
	typename Set
>
Set
set_intersection(
	Set const &a,
	Set const &b
)
{
	Set result;

	::std::set_intersection(
		a.begin(),
		a.end(),
		b.begin(),
		b.end(),
		::std::inserter(
			result,
			result.begin()
		)
	);

	return result;
}

}
}

#endif
