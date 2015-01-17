//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_CLAMP_POS_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_CLAMP_POS_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Clamps an unsigned position to a grid's size

\ingroup fcpptcontainergrid
*/
template<
	typename Source,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos<
	Source,
	Size
> const
clamp_pos(
	fcppt::container::grid::pos<
		Source,
		Size
	> const _pos,
	fcppt::container::grid::dim<
		Source,
		Size
	> const _size
)
{
	static_assert(
		std::is_unsigned<
			Source
		>::value,
		"Source must be unsigned"
	);

	typedef
	fcppt::container::grid::pos<
		Source,
		Size
	> result_type;

	result_type ret{
		fcppt::no_init()
	};

	for(
		auto const index
		:
		fcppt::make_int_range_count(
			result_type::dim_wrapper::value
		)
	)
		ret[
			index
		] =
			std::min(
				_pos[
					index
				],
				_size[
					index
				]
			);

	return
		ret;
}

}
}
}

#endif
