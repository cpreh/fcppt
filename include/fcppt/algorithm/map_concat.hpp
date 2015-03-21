//          Copyright Carl Philipp Reh 2009 - 2015.
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
\brief Maps a sequence to other sequences and joins them

\ingroup fcpptalgorithm

For every element in \a _source (a_1, ..., a_n), _function(a_1), ...,
_function(a_n) is called, yielding (r_1, ..., r_n). The result is
join(join(r_1, r_2), ..., r_n).

\param _function A function accepting elements from \a _source and returning an
object of type \a TargetContainer.

\param _source The sequence to be mapped.
*/
template<
	typename TargetContainer,
	typename SourceContainer,
	typename Function
>
TargetContainer
map_concat(
	SourceContainer &&_source,
	Function const &_function
)
{
	return
		fcppt::algorithm::detail::map_concat<
			TargetContainer
		>(
			std::forward<
				SourceContainer
			>(
				_source
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
