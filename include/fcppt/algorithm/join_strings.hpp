//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_JOIN_STRINGS_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_STRINGS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
 * \brief Joins a range of items delimited by \p delim
 * \param _range A forward-iterable range. The range's value_type must have an <code>operator+=</code>
 * \param _delim The delimiting value
 * \ingroup fcpptalgorithm
 * \details Example:
 *
 * \snippet doc/algorithm.cpp join_strings
 */
template
<
	typename Range
>
typename Range::value_type const
join_strings(
	Range const &_range,
	typename Range::value_type const &_delim
)
{
	typename Range::value_type result;

	for(
		typename Range::const_iterator it(
			_range.begin()
		);
		it != _range.end();
		++it
	)
	{
		result += *it;

		if(
			std::next(
				it
			)
			!= _range.end()
		)
			result += _delim;
	}

	return result;
}
}
}

#endif
