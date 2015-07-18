//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OFFSET_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OFFSET_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns the absolute offset of a position

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
SizeType
offset(
	fcppt::container::grid::pos<
		SizeType,
		Size
	> const &_pos,
	fcppt::container::grid::dim<
		SizeType,
		Size
	> const &_size
)
{
	auto const one(
		fcppt::literal<
			fcppt::container::grid::size_type
		>(
			1
		)
	);

	SizeType result{
		_pos.x()
	};

	SizeType stacked_dim{
		one
	};

	for(
		fcppt::container::grid::size_type const index
		:
		fcppt::make_int_range(
			one,
			Size
		)
	)
	{
		stacked_dim *=
			_size[
				index
				-
				one
			];

		result +=
			_pos[
				index
			]
			*
			stacked_dim;
	}

	return
		result;

}

}
}
}

#endif
