//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/resize_preserve.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_resize_preverse
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		std::pair<
			fcppt::container::grid::size_type,
			fcppt::container::grid::size_type
		>,
		2
	>
	sz_pair_grid;

	sz_pair_grid test(
		sz_pair_grid::dim(
			5u,
			10u
		),
		fcppt::no_init{}
	);

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size()[1]
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size()[0]
			)
		)
			test[
				sz_pair_grid::pos(
					x,
					y
				)
			] =
				std::make_pair(
					x,
					y
				);

	fcppt::container::grid::resize_preserve(
		test,
		sz_pair_grid::dim(
			3u,
			5u
		)
	);

	BOOST_CHECK_EQUAL(
		test.size(),
		sz_pair_grid::dim(
			3u,
			5u
		)
	);

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size()[1]
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size()[0]
			)
		)
		{
			BOOST_CHECK(
				test[
					sz_pair_grid::pos(
						x,
						y
					)
				]
				==
				std::make_pair(
					fcppt::cast::size<
						fcppt::container::grid::size_type
					>(
						x
					),
					fcppt::cast::size<
						fcppt::container::grid::size_type
					>(
						y
					)
				)
			);
		}
}
