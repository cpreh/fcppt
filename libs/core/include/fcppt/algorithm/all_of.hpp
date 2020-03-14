//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ALL_OF_HPP_INCLUDED
#define FCPPT_ALGORITHM_ALL_OF_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a given predicate is true for all elements of a range.

\ingroup fcpptalgorithm

\tparam Pred A function callable as <code>bool (Range::value_type)</code>.
*/
template<
	typename Range,
	typename Pred
>
inline
bool
all_of(
	Range const &_range,
	Pred const &_pred
)
{
	bool result{
		true
	};

	fcppt::algorithm::loop_break(
		_range,
		[
			&_pred,
			&result
		](
			auto const &_element
		)
		{
			if(
				_pred(
					_element
				)
			)
			{
				return
					fcppt::loop::continue_;
			}

			result =
				false;

			return
				fcppt::loop::break_;
		}
	);

	return
		result;
}

}
}

#endif
