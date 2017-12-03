//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_SINGULAR_RANGE_HPP_INCLUDED
#define FCPPT_ITERATOR_SINGULAR_RANGE_HPP_INCLUDED

#include <fcppt/iterator/range_empty.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Range
>
bool
singular_range(
	Range const &_range
)
{
	return
		!fcppt::iterator::range_empty(
			_range
		)
		&&
		std::next(
			_range.begin()
		)
		==
		_range.end();
}

}
}

#endif
