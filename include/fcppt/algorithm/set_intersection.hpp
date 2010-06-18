//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SET_INTERSECTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_SET_INTERSECTION_HPP_INCLUDED

#include <algorithm>
#include <iterator>

namespace fcppt
{
namespace algorithm
{

/// Calculates the intersection of two sets
/**
 * Equivalent to
 * std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result, result.begin()));
 * return result;
*/
template<
	typename Set
>
Set const
set_intersection(
	Set const &a,
	Set const &b
)
{
	Set result;

	std::set_intersection(
		a.begin(),
		a.end(),
		b.begin(),
		b.end(),
		std::inserter(
			result,
			result.begin()
		)
	);

	return result;
}

}
}

#endif
