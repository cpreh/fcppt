//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/apply.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::apply",
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

	uint_grid const grid1(
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

	string_grid const grid2(
		string_grid::dim{
			2u,
			3u
		},
		[](
			string_grid::pos const _pos
		)
		{
			return
				std::to_string(
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

	auto const function(
		[](
			unsigned const _value1,
			std::string const &_value2
		)
		{
			return
				std::to_string(
					_value1
				)
				+
				_value2
				;
		}
	);

	string_grid const result(
		fcppt::container::grid::apply(
			function,
			grid1,
			grid2
		)
	);

	// TODO: Compare the whole grids
	REQUIRE(
		grid1.size()
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
			"00"
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
			"33"
		)
	);

	CHECK(
		fcppt::container::grid::apply(
			function,
			grid1,
			string_grid()
		).size()
		==
		string_grid::dim(
			0u,
			0u
		)
	);
}
