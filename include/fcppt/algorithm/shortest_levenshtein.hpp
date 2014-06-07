//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SHORTEST_LEVENSHTEIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_SHORTEST_LEVENSHTEIN_HPP_INCLUDED

#include <fcppt/algorithm/levenshtein.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/iterator.hpp>
#include <boost/range/reference.hpp>
#include <boost/range/value_type.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/// Returns the array element with the shortest levenshtein distance
/// to the "ref" element. Undefined if _container.empty().
///
template<
	typename Range,
	typename Value
>
typename
boost::range_reference<
	Range
>::type
shortest_levenshtein(
	Range &_range,
	Value const &_element
)
{
	typedef typename
	boost::range_value<
		Range
	>::type
	string_type;

	typedef typename
	string_type::size_type
	size_type;

	typedef typename
	boost::range_iterator<
		Range
	>::type
	iterator;

	size_type shortest_dist(
		::fcppt::algorithm::levenshtein(
			*boost::begin(
				_range),
			_element
		)
	);

	iterator shortest(
		boost::begin(
			_range)
	);

	for(
		iterator it(
			std::next(
				boost::begin(
					_range)
			)
		);
		it != boost::end(_range);
		++it
	)
	{
		size_type const new_shortest_dist(
			::fcppt::algorithm::levenshtein(
				*it,
				_element
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

template<
	typename Range,
	typename Value
>
typename
boost::range_reference<
	Range const
>::type
shortest_levenshtein(
	Range const &_range,
	Value const &_element
)
{
	return
		fcppt::algorithm::shortest_levenshtein<
			Range const
		>(
			_range,
			_element
		);
}

}
}

#endif
