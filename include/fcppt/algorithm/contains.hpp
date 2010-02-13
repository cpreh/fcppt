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

/// Checks if a given element is inside a range 
/** Equivalent to find(beg, end, value) != end
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

}
}

#endif
