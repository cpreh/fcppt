//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_APPEND_HPP_INCLUDED
#define FCPPT_ALGORITHM_APPEND_HPP_INCLUDED

#include <fcppt/move_iterator_if_rvalue.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Appends two sequences.

\ingroup fcpptalgorithm

Appends the sequence \a _src to \a _dest.

Example:

\snippet algorithm.cpp append

\tparam DestContainer Must have an insert function taking three iterators (like the std containers all do).
**/
template<
	typename DestContainer,
	typename Source
>
inline
void
append(
	DestContainer &_dest,
	Source &&_src
)
{
	_dest.insert(
		_dest.end(),
		fcppt::move_iterator_if_rvalue<
			Source
		>(
			_src.begin()
		),
		fcppt::move_iterator_if_rvalue<
			Source
		>(
			_src.end()
		)
	);
}

}
}

#endif
