//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/in_range_dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_in_range_dim
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::pos<
		std::size_t,
		2u
	>
	int2_pos;

	typedef
	fcppt::container::grid::dim<
		std::size_t,
		2u
	>
	int2_dim;

	int2_dim const test{
		3u,
		4u
	};

	BOOST_CHECK(
		fcppt::container::grid::in_range_dim(
			test,
			int2_pos(
				2u,
				2u
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::grid::in_range_dim(
			test,
			int2_pos(
				3u,
				2u
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::grid::in_range_dim(
			test,
			int2_pos(
				2u,
				4U
			)
		)
	);
}
