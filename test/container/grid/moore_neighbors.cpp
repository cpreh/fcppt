//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/moore_neighbor_array.hpp>
#include <fcppt/container/grid/moore_neighbors.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::container::grid::pos<
	unsigned,
	2
>
pos;

typedef
fcppt::container::grid::moore_neighbor_array<
	pos
>
array;

bool
contains_element(
	array const &_result,
	pos const _pos
)
{
	return
		std::find(
			_result.begin(),
			_result.end(),
			_pos
		);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_moore_neighbors
)
{
FCPPT_PP_POP_WARNING

	array const result(
		fcppt::container::grid::moore_neighbors(
			pos(
				5u,
				7u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				4u,
				7u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				6u,
				7u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				5u,
				6u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				5u,
				8u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				4u,
				6u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				6u,
				6u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				4u,
				8u
			)
		)
	);

	BOOST_CHECK(
		contains_element(
			result,
			pos(
				6u,
				8u
			)
		)
	);
}
