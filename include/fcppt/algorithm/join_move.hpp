//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_JOIN_MOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_MOVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/variadic_fold.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Joins two containers by moving their contents

Joins containers \a _first and \a _args, by recursively inserting all
containers from \a _args into \a _first.

\ingroup fcpptalgorithm

\param _first The left container

\param _args The other containers, which will be inserted into the left
container

\tparam Container A container class that supports insert of iterator ranges
*/
template<
	typename Container,
	typename... Args
>
Container
join_move(
	Container &&_first,
	Args && ..._args
)
{
	return
		fcppt::algorithm::detail::variadic_fold(
			[](
				Container &&_left,
				Container &&_right
			)
			{
				_left.insert(
					_left.end(),
					std::make_move_iterator(
						_right.begin()
					),
					std::make_move_iterator(
						_right.end()
					)
				);

				return
					std::move(
						_left
					);
			},
			std::move(
				_first
			),
			std::forward<
				Args
			>(
				_args
			)...
		);
}

}
}

#endif
