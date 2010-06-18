//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace algorithm
{

/// Checks if a given @a value is inside the range [@a beg @a end ]
/**
 * Equivalent to find(beg, end, value) != end
*/
template<
	typename In,
	typename T
>
bool
contains(
	In const beg,
	In const end,
	T const &value
)
{
	return
		std::find(
			beg,
			end,
			value
		)
		!= end;
}

/// Checks if a given @a value is in the container @a container
/**
 * Equivalent to contains(container.begin(), container.end(), value)
*/
template<
	typename Container,
	typename T
>
bool
contains(
	Container const &container,
	T const &value
)
{
	return
		algorithm::contains(
			container.begin(),
			container.end(),
			value
		);
}

}
}

#endif
