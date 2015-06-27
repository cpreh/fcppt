//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/next_position.hpp>
#include <fcppt/container/grid/pos_iterator_decl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/vector/comparison.hpp>


template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos_iterator<
	SizeType,
	Size
>::pos_iterator(
	pos const _current,
	min const _min,
	sup const _sup
)
:
	current_(
		_current
	),
	min_(
		_min
	),
	sup_(
		_sup
	)
{
}

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
void
fcppt::container::grid::pos_iterator<
	SizeType,
	Size
>::increment()
{
	current_ =
		fcppt::container::grid::next_position(
			current_,
			min_,
			sup_
		);
}

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
typename
fcppt::container::grid::pos_iterator<
	SizeType,
	Size
>::reference
fcppt::container::grid::pos_iterator<
	SizeType,
	Size
>::dereference() const
{
	return
		current_;
}

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
bool
fcppt::container::grid::pos_iterator<
	SizeType,
	Size
>::equal(
	pos_iterator const &_other
) const
{
	return
		current_
		==
		_other.current_;
}

#endif
