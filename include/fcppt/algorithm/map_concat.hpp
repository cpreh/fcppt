//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_CONCAT_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_CONCAT_HPP_INCLUDED

#include <fcppt/algorithm/join.hpp>
#include <fcppt/algorithm/detail/map_concat.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Maps a range to other sequences and joins them.

\ingroup fcpptalgorithm

For every element in \a _range <code>(a_1, ..., a_n)</code>,
<code>_function(a_1), ..., _function(a_n)</code> is called, yielding
<code>(r_1, ..., r_n)</code>. The result is <code>join(r_1, r_2, ...,
r_n)</code>.

\tparam Function A function callable as <code>TargetContainer
(Range::value_type)</code>.
*/
template<
	typename TargetContainer,
	typename Range,
	typename Function
>
TargetContainer
map_concat(
	Range &&_range,
	Function const &_function
)
{
	return
		fcppt::algorithm::detail::map_concat<
			TargetContainer
		>(
			std::forward<
				Range
			>(
				_range
			),
			_function,
			[](
				TargetContainer &&_state1,
				TargetContainer &&_state2
			)
			{
				return
					fcppt::algorithm::join(
						std::move(
							_state1
						),
						std::move(
							_state2
						)
					);
			}
		);
}

}
}

#endif
