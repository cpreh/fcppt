//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/map.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::map",
	"[container],[grid]"
)
{
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

	REQUIRE(
		grid.size()
		==
		result.size()
	);

	CHECK(
		result.get_unsafe(
			string_grid::pos(
				0u,
				0u
			)
		)
		==
		std::string(
			"0"
		)
	);

	CHECK(
		result.get_unsafe(
			string_grid::pos(
				1u,
				2u
			)
		)
		==
		std::string(
			"3"
		)
	);
}

TEST_CASE(
	"container::grid::map move",
	"[container],[grid]"
)
{
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

	REQUIRE(
		strong_grid::dim(
			3u,
			2u
		)
		==
		result.size()
	);

	CHECK(
		*result.get_unsafe(
			strong_grid::pos(
				0u,
				0u
			)
		).get()
		==
		0u
	);

	CHECK(
		*result.get_unsafe(
			strong_grid::pos(
				2u,
				1u
			)
		).get()
		==
		3u
	);
}
