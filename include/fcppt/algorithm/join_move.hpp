//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_JOIN_MOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_MOVE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Joins two containers by moving their contents

Joins containers \a _left and \a _right, by inserting \a _right into \a _left.

\ingroup fcpptalgorithm

\param _left The left container

\param _right The right container, which will be inserted into the left
container

\tparam Container A container class that supports insert of iterator ranges
*/
template
<
	typename Container
>
Container
join_move(
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
}

}
}

#endif
