//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_RANGE_EMPTY_HPP_INCLUDED
#define FCPPT_ITERATOR_RANGE_EMPTY_HPP_INCLUDED


namespace fcppt
{
namespace iterator
{

template<
	typename Range
>
bool
range_empty(
	Range const &_range
)
{
	return
		_range.begin()
		==
		_range.end();
}

}
}

#endif
