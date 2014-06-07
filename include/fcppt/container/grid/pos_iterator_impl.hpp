//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_decl.hpp>
#include <fcppt/container/grid/pos_reference_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_iterator<
	Grid
>::pos_iterator(
	iterator const &_iterator,
	dim const &_size,
	pos const &_current,
	pos const &_min,
	pos const &_max,
	bool const _is_end
)
:
	iterator_(
		_iterator
	),
	size_(
		_size
	),
	current_(
		_current
	),
	min_(
		_min
	),
	max_(
		_max
	),
	is_end_(
		_is_end
	)
{
}

template<
	typename Grid
>
void
fcppt::container::grid::pos_iterator<
	Grid
>::increment()
{
	// TODO: Generalize this!
	if(
		++current_.x()
		==
		max_.x()
	)
	{
		current_.x() = min_.x();

		++current_.y();
	}
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_iterator<
	Grid
>::reference
fcppt::container::grid::pos_iterator<
	Grid
>::dereference() const
{
	return
		reference(
			current_,
			*(
				iterator_
				+
				fcppt::cast::to_signed(
					current_.x()
					+
					current_.y()
					*
					size_.w()
				)
			)
		);
}

template<
	typename Grid
>
bool
fcppt::container::grid::pos_iterator<
	Grid
>::equal(
	pos_iterator const &_other
) const
{
	return
		is_end_
		!=
		_other.is_end_
		?
			current_.x()
			==
			_other.current_.x()
			||
			current_.y()
			==
			_other.current_.y()
		:
			current_
			==
			_other.current_;
}

#endif
