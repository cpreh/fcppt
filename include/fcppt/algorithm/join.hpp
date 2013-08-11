//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_JOIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_HPP_INCLUDED


namespace fcppt
{
namespace algorithm
{

/**
\brief Joins two containers

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
join(
	Container _left,
	Container const &_right
)
{
	_left.insert(
		_left.end(),
		_right.begin(),
		_right.end()
	);

	return _left;
}

}
}

#endif
