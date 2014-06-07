//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_APPEND_RESULT_HPP_INCLUDED
#define FCPPT_ALGORITHM_APPEND_RESULT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


/**
\brief Appends two sequences by moving, returning the result.

\ingroup fcpptalgorithm

Appends \a _src to \a _dest and returns the result. All elements from _src are
moved to \a _dest.
*/
namespace fcppt
{
namespace algorithm
{

template<
	typename DestContainer,
	typename SourceContainer
>
DestContainer
append_result(
	DestContainer &&_dest,
	SourceContainer &&_src
)
{
	_dest.insert(
		_dest.end(),
		std::make_move_iterator(
			_src.begin()
		),
		std::make_move_iterator(
			_src.end()
		)
	);

	return
		std::move(
			_dest
		);
}

}
}

#endif
