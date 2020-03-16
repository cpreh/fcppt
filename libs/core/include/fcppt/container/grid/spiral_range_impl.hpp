//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_SPIRAL_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SPIRAL_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/spiral_iterator_impl.hpp>
#include <fcppt/container/grid/spiral_range_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Pos
>
fcppt::container::grid::spiral_range<
	Pos
>::spiral_range(
	Pos _start,
	value_type const _dist
)
:
	start_(
		std::move(
			_start
		)
	),
	dist_(
		_dist
	)
{
}

template<
	typename Pos
>
typename
fcppt::container::grid::spiral_range<
	Pos
>::iterator
fcppt::container::grid::spiral_range<
	Pos
>::begin() const
{
	return
		iterator(
			start_,
			dist_
		);
}

template<
	typename Pos
>
typename
fcppt::container::grid::spiral_range<
	Pos
>::iterator
fcppt::container::grid::spiral_range<
	Pos
>::end() const
{
	return
		iterator(
			Pos(
				start_.x()
				-
				1,
				start_.y()
				-
				dist_
			),
			dist_
		);
}

#endif
