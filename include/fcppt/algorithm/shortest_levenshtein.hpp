//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SHORTEST_LEVENSHTEIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_SHORTEST_LEVENSHTEIN_HPP_INCLUDED

#include <fcppt/algorithm/levenshtein.hpp>
#include <boost/foreach.hpp>

namespace fcppt
{
namespace algorithm
{
/// Returns the array element with the shortest levenshtein distance
/// to the "ref" element. Undefined if c.empty().
/// 
/// FIXME: Have a nonconst version for this? Base this on iterators?
template<typename Container>
typename 
Container::const_reference
shortest_levenshtein(
	Container const &c,
	typename Container::const_reference ref)
{
	typedef typename 
	Container::value_type
	string_type;

	typedef typename 
	string_type::size_type
	size_type;

	size_type shortest_dist = 
		::fcppt::algorithm::levenshtein(
			*c.begin(),
			ref);

	string_type const *shortest = 
		&(*c.begin());

	BOOST_FOREACH(
		typename Container::const_reference r,
		c)
	{
		size_type const new_shortest_dist =
			::fcppt::algorithm::levenshtein(
				r,
				ref);

		if (new_shortest_dist < shortest_dist)
		{
			shortest = &r;
			shortest_dist = new_shortest_dist;
		}
	}

	return *shortest;
}
}
}

#endif
