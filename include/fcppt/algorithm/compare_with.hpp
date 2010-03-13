//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_COMPARE_WITH_HPP_INCLUDED
#define FCPPT_ALGORITHM_COMPARE_WITH_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace algorithm
{

/// Compares two sequences element by element, using @a function
template<
	typename Container,
	typename Function
>
bool
compare_with(
	Container const &a,
	Container const &b,
	Function const &function
)
{
	return
		a.size() == b.size()
		&& std::equal(
			a.begin(),
			a.end(),
			b.begin(),
			function
		);

}

}
}

#endif
