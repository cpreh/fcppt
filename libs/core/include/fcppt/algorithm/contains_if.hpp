//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED

#include <fcppt/range/begin.hpp>
#include <fcppt/range/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a given value is inside a range, using a predicate.

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
	auto const range_end{
		fcppt::range::end(
			_range
		)
	};

	return
		std::find_if(
			fcppt::range::begin(
				_range
			),
			range_end,
			_pred
		)
		!=
		range_end;
}

}
}

#endif
