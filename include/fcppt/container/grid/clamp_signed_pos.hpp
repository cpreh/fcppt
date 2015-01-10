//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_CLAMP_SIGNED_POS_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_CLAMP_SIGNED_POS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/clamp.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Clamps a signed position to a grid's size

\ingroup fcpptcontainergrid
*/
template<
	typename Dest,
	typename Source,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos<
	Dest,
	Size
> const
clamp_signed_pos(
	fcppt::container::grid::pos<
		Source,
		Size
	> const _pos,
	fcppt::container::grid::dim<
		Dest,
		Size
	> const _size
)
{
	static_assert(
		std::is_signed<
			Source
		>::value,
		"Source must be signed"
	);

	static_assert(
		std::is_unsigned<
			Dest
		>::value,
		"Dest must be unsigned"
	);

	FCPPT_ASSERT_PRE(
		_size.content()
		!=
		0u
	);

	typedef
	fcppt::container::grid::pos<
		Dest,
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
			fcppt::cast::to_unsigned(
				fcppt::math::clamp(
					_pos[
						index
					],
					fcppt::literal<
						Source
					>(
						0
					),
					fcppt::cast::to_signed(
						_size[
							index
						]
					)
				)
			);

	return ret;
}

}
}
}

#endif
