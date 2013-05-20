//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_iterator_decl.hpp>
#include <fcppt/container/grid/pos_reference_impl.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_iterator<
	Grid
>::pos_iterator(
	iterator const &_iterator,
	dim const &_size,
	dim const &_pos,
	dim const &_min,
	dim const &_max,
	bool const _is_end
)
:
	iterator_(
		_iterator
	),
	size_(
		_size
	),
	pos_(
		_pos
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
		++pos_.w()
		==
		max_.w()
	)
	{
		pos_.w() = min_.w();

		++pos_.h();
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
			pos_,
			*(
				iterator_
				+
				static_cast<
					typename
					std::iterator_traits<
						iterator
					>::difference_type
				>(
					pos_.w()
					+
					pos_.h()
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
			pos_.w()
			==
			_other.pos_.w()
			||
			pos_.h()
			==
			_other.pos_.h()
		:
			pos_
			==
			_other.pos_;
}

#endif
