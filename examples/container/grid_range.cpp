//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/make_pos_range.hpp>
#include <fcppt/container/grid/make_pos_ref_crange.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_reference.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
pos_range()
{
// ![pos_range]
	typedef
	fcppt::container::grid::pos<
		fcppt::container::grid::size_type,
		2
	>
	pos2;

	typedef
	fcppt::container::grid::dim<
		fcppt::container::grid::size_type,
		2
	>
	dim2;

	// Outputs: (0,0), (1,0), (0,1), (1,1), (0,2), (1,2)
	for(
		pos2 const &pos
		:
		fcppt::container::grid::make_pos_range(
			dim2{
				2u,
				3u
			}
		)
	)
		std::cout
			<< pos
			<< '\n';
// ![pos_range]
}

void
pos_ref_range()
{
// ![pos_ref_range]
	typedef
	fcppt::container::grid::object<
		unsigned,
		2
	>
	uint2_grid;

	uint2_grid const grid(
		uint2_grid::dim{
			2,
			2
		},
		[](
			uint2_grid::pos const _pos
		)
		{
			return
				fcppt::cast::size<
					unsigned
				>(
					_pos.x()
					+
					_pos.y()
				);
		}
	);

	typedef
	fcppt::container::grid::pos_reference<
		uint2_grid const
	>
	pos_ref;

	// Outputs: (0,0): 0, (1,0): 1, (0,1): 1, (1,1): 2
	for(
		pos_ref const &ref
		:
		fcppt::container::grid::make_pos_ref_crange(
			grid
		)
	)
		std::cout
			<< ref.pos()
			<< ": "
			<< ref.value()
			<< '\n';

// ![pos_ref_range]
}


}

int
main()
{
	pos_range();

	pos_ref_range();
}
