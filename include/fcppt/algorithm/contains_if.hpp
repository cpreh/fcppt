//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a given \p value is inside a range

\ingroup fcpptalgorithm

\tparam Pred A function callable as <code>bool (Range::value_type)</code>.
*/
template<
	typename Range,
	typename Pred
>
inline
bool
contains_if(
	Range const &_range,
	Pred const &_pred
)
{
	return
		std::find_if(
			_range.begin(),
			_range.end(),
			_pred
		)
		!=
		_range.end();
}

}
}

#endif
