//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_RANGE_COMPARISON_HPP_INCLUDED
#define FCPPT_ITERATOR_RANGE_COMPARISON_HPP_INCLUDED

#include <fcppt/iterator/range_impl.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Iterator
>
inline
bool
operator==(
	fcppt::iterator::range<
		Iterator
	> const &_left,
	fcppt::iterator::range<
		Iterator
	> const &_right
)
{
	return
		_left.begin()
		==
		_right.begin()
		&&
		_left.end()
		==
		_right.end();
}

template<
	typename Iterator
>
inline
bool
operator!=(
	fcppt::iterator::range<
		Iterator
	> const &_left,
	fcppt::iterator::range<
		Iterator
	> const &_right
)
{
	return
		!(
			_left
			==
			_right
		);
}

}
}

#endif
