//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a given value is inside a range, using a predicate.

\ingroup fcpptalgorithm

\tparam Pred A function callable as <code>bool (T)</code> for all types T that appear in \a Range.
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
	bool result{
		false
	};

	fcppt::algorithm::loop_break(
		_range,
		[
			&result,
			&_pred
		](
			auto const &_value
		)
		{
			if(
				_pred(
					_value
				)
			)
			{
				result =
					true;

				return
					fcppt::loop::break_;
			}

			return
				fcppt::loop::continue_;
		}
	);

	return
		result;
}

}
}

#endif
