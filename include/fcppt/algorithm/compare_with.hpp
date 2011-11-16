//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_COMPARE_WITH_HPP_INCLUDED
#define FCPPT_ALGORITHM_COMPARE_WITH_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief Compares two sequences element by element, using \p function
 * \ingroup fcpptalgorithm
 * \tparam Function A binary functor
 *
 * If <code>a.size() != b.size()</code>, the function returns
 * <code>false</code>
 **/
template<
	typename Container1,
	typename Container2,
	typename Function
>
bool
compare_with(
	Container1 const &a,
	Container2 const &b,
	Function const &function
)
{
	return
		a.size() == b.size()
		&& ::std::equal(
			a.begin(),
			a.end(),
			b.begin(),
			function
		);

}

}
}

#endif
