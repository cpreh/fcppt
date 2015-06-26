//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/container/grid/end_position.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_range_decl.hpp>
#include <fcppt/container/grid/pos_ref_iterator_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>
#include <fcppt/config/external_end.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_range<
	Grid
>::pos_range(
	Grid &_grid,
	min const _min,
	sup const _sup
)
:
	grid_(
		_grid
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
	typename Grid
>
typename
fcppt::container::grid::pos_range<
	Grid
>::iterator
fcppt::container::grid::pos_range<
	Grid
>::begin() const
{
	return
		this->make_iterator(
			min_.get()
		);
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_range<
	Grid
>::iterator
fcppt::container::grid::pos_range<
	Grid
>::end() const
{
	return
		fcppt::algorithm::contains_if(
			boost::range::combine(
				min_.get(),
				sup_.get()
			),
			[](
				boost::tuple<
					fcppt::container::grid::size_type,
					fcppt::container::grid::size_type
				> const _val
			)
			{
				return
					boost::get<
						0
					>(
						_val
					)
					>=
					boost::get<
						1
					>(
						_val
					);
			}
		)
		?
			this->begin()
		:
			this->make_iterator(
				fcppt::container::grid::end_position(
					min_,
					sup_
				)
			)
		;
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_range<
	Grid
>::iterator
fcppt::container::grid::pos_range<
	Grid
>::make_iterator(
	pos const _pos
) const
{
	return
		iterator(
			grid_.begin(),
			grid_.size(),
			_pos,
			min_,
			sup_
		);
}

#endif
