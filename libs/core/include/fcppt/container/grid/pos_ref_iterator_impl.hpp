//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/offset.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_ref_iterator_decl.hpp>
#include <fcppt/container/grid/pos_reference_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_ref_iterator<
	Grid
>::pos_ref_iterator(
	iterator const &_iterator,
	pos_iterator const &_pos_iterator,
	dim const _size
)
:
	iterator_(
		_iterator
	),
	pos_iterator_(
		_pos_iterator
	),
	size_(
		_size
	)
{
}

template<
	typename Grid
>
void
fcppt::container::grid::pos_ref_iterator<
	Grid
>::increment()
{
	++pos_iterator_;
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_ref_iterator<
	Grid
>::reference
fcppt::container::grid::pos_ref_iterator<
	Grid
>::dereference() const
{
	pos const current(
		*pos_iterator_
	);

	return
		reference(
			current,
			*(
				iterator_
				+
				fcppt::cast::to_signed(
					fcppt::container::grid::offset(
						current,
						size_
					)
				)
			)
		);
}

template<
	typename Grid
>
bool
fcppt::container::grid::pos_ref_iterator<
	Grid
>::equal(
	pos_ref_iterator const &_other
) const
{
	return
		pos_iterator_
		==
		_other.pos_iterator_;
}

#endif
