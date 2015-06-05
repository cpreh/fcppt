//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_ITERATOR_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_ITERATOR_POSITION_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns the position of an iterator
\ingroup fcpptcontainergrid
\warning
Behavior is undefined if the iterator doesn't belong to the given grid.
*/
template<
	typename Grid,
	typename Iterator
>
typename
Grid::pos const
iterator_position(
	Grid const &_grid,
	Iterator const _it
)
{
	typedef
	typename
	Grid::pos
	pos;

	typedef
	typename
	Grid::dim
	dim;

	typedef
	typename
	dim::value_type
	dim_unit;

	typedef
	typename
	pos::size_type
	dim_size_type;

	dim stacked_dim{
		fcppt::no_init()
	};

	stacked_dim[0] = _grid.size()[0];

	for(
		dim_size_type const index
		:
		fcppt::make_int_range(
			1u,
			stacked_dim.size()
		)
	)
		stacked_dim[
			index
		] =
			stacked_dim[
				index
				-
				fcppt::literal<
					dim_size_type
				>(
					1
				)
			]
			*
			_grid.size()[
				index
			];

	pos ret{
		fcppt::no_init()
	};

	dim_unit const offset(
		fcppt::cast::to_unsigned(
			std::distance(
				_grid.begin(),
				_it
			)
		)
	);

	for(
		dim_size_type const i
		:
		fcppt::make_int_range_count(
			dim::dim_wrapper::value
		)
	)
	{
		ret[i] = offset;

		for(
			dim_size_type m =
				dim::dim_wrapper::value
				-
				fcppt::literal<
					dim_size_type
				>(
					1
				);
			m > i;
			--m
		)
			ret[i] =
				ret[i] % stacked_dim[i];

		if(
			i
			>
			fcppt::literal<
				dim_size_type
			>(
				0
			)
		)
			ret[i] =
				ret[i]
				/
				stacked_dim[
					i
					-
					fcppt::literal<
						dim_size_type
					>(
						1
					)
				];
	}

	return
		ret;
}

}
}
}

#endif
