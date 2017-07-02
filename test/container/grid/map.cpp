//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/map.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		std::string,
		2
	>
	string_grid;

	typedef
	fcppt::container::grid::object<
		unsigned,
		2
	>
	uint_grid;

	uint_grid const grid(
		uint_grid::dim{
			2u,
			3u
		},
		[](
			uint_grid::pos const _pos
		)
		{
			return
				fcppt::cast::size<
					unsigned
				>(
					fcppt::math::vector::at<
						0
					>(
						_pos
					)
					+
					fcppt::math::vector::at<
						1
					>(
						_pos
					)
				);
		}
	);

	string_grid const result(
		fcppt::container::grid::map(
			grid,
			[](
				unsigned const _value
			)
			{
				return
					std::to_string(
						_value
					);
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		grid.size(),
		result.size()
	);

	BOOST_CHECK_EQUAL(
		result.get_unsafe(
			string_grid::pos(
				0u,
				0u
			)
		),
		std::string(
			"0"
		)
	);

	BOOST_CHECK_EQUAL(
		result.get_unsafe(
			string_grid::pos(
				1u,
				2u
			)
		),
		std::string(
			"3"
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_map_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		unsigned
	>
	uint_unique_ptr;

	FCPPT_MAKE_STRONG_TYPEDEF(
		uint_unique_ptr,
		strong_result
	);

	typedef
	fcppt::container::grid::object<
		uint_unique_ptr,
		2
	>
	unique_ptr_grid;

	typedef
	fcppt::container::grid::object<
		strong_result,
		2
	>
	strong_grid;


	strong_grid const result(
		fcppt::container::grid::map(
			unique_ptr_grid(
				unique_ptr_grid::dim{
					3u,
					2u
				},
				[](
					unique_ptr_grid::pos const _pos
				)
				{
					return
						fcppt::make_unique_ptr<
							unsigned
						>(
							fcppt::cast::size<
								unsigned
							>(
								fcppt::math::vector::at<
									0
								>(
									_pos
								)
								+
								fcppt::math::vector::at<
									1
								>(
									_pos
								)
							)
						);
				}
			),
			[](
				uint_unique_ptr &&_value
			)
			{
				return
					strong_result(
						std::move(
							_value
						)
					);
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		strong_grid::dim(
			3u,
			2u
		),
		result.size()
	);

	BOOST_CHECK_EQUAL(
		*result.get_unsafe(
			strong_grid::pos(
				0u,
				0u
			)
		).get(),
		0u
	);

	BOOST_CHECK_EQUAL(
		*result.get_unsafe(
			strong_grid::pos(
				2u,
				1u
			)
		).get(),
		3u
	);
}
