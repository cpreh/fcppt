//          Copyright Carl Philipp Reh 2009 - 2014.
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
\ingroup fcpptalgorithm
*/
template<
	typename TargetContainer,
	typename SourceContainer,
	typename Function
>
TargetContainer
map_concat(
	SourceContainer const &_source,
	Function const &_function
)
{
	return
		fcppt::algorithm::detail::map_concat<
			TargetContainer
		>(
			_source,
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
