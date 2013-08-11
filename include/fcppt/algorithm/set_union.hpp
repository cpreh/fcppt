//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SET_UNION_HPP_INCLUDED
#define FCPPT_ALGORITHM_SET_UNION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/// Calculates the union of two sets
/**
 * Equivalent to
 * std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result, result.begin()));
 * return result;
*/
template<
	typename Set
>
Set
set_union(
	Set const &a,
	Set const &b
)
{
	Set result;

	::std::set_union(
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
