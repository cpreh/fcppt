//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns the next position in a grid range

\ingroup fcpptcontainergrid

Given a range by \a _min and \a _sup, returns the next position after \a
_current.
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos<
	SizeType,
	Size
>
next_position(
	fcppt::container::grid::pos<
		SizeType,
		Size
	> const _current,
	fcppt::container::grid::min<
		SizeType,
		Size
	> const _min,
	fcppt::container::grid::sup<
		SizeType,
		Size
	> const _sup
)
{
	auto const one(
		fcppt::literal<
			fcppt::container::grid::size_type
		>(
			1
		)
	);

	fcppt::container::grid::pos<
		SizeType,
		Size
	> result{
		_current
	};

	++result.x();

	for(
		fcppt::container::grid::size_type const index
		:
		fcppt::make_int_range_count(
			Size
			-
			one
		)
	)
		if(
			result[
				index
			]
			==
			_sup.get()[
				index
			]
		)
		{
			result[
				index
			] =
				_min.get()[
					index
				];

			++result[
				index
				+
				one
			];
		}

	return
		result;
}

}
}
}

#endif
