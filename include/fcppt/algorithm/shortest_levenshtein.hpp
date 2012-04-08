//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SHORTEST_LEVENSHTEIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_SHORTEST_LEVENSHTEIN_HPP_INCLUDED

#include <fcppt/algorithm/levenshtein.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/next_prior.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/// Returns the array element with the shortest levenshtein distance
/// to the "ref" element. Undefined if _container.empty().
///
/// FIXME: Have a nonconst version for this? Base this on iterators?
template<
	typename Container
>
typename
Container::const_reference
shortest_levenshtein(
	Container const &_container,
	typename Container::const_reference _ref
)
{
	typedef typename
	Container::value_type
	string_type;

	typedef typename
	string_type::size_type
	size_type;

	typedef typename
	Container::const_iterator
	const_iterator;

	size_type shortest_dist(
		::fcppt::algorithm::levenshtein(
			*_container.begin(),
			_ref
		)
	);

	const_iterator shortest(
		_container.begin()
	);

	for(
		const_iterator it(
			boost::next(
				_container.begin()
			)
		);
		it != _container.end();
		++it
	)
	{
		size_type const new_shortest_dist(
			::fcppt::algorithm::levenshtein(
				*it,
				_ref
			)
		);

		if(
			new_shortest_dist < shortest_dist
		)
		{
			shortest = it;

			shortest_dist = new_shortest_dist;
		}
	}

	return *shortest;
}

}
}

#endif
