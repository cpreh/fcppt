//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/apply.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_apply
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
					fcppt::math::at_c<
						0
					>(
						_pos
					)
					+
					fcppt::math::at_c<
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
					fcppt::math::at_c<
						0
					>(
						_pos
					)
					+
					fcppt::math::at_c<
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

	BOOST_REQUIRE_EQUAL(
		grid1.size(),
		result.size()
	);

	BOOST_CHECK_EQUAL(
		result[
			string_grid::pos(
				0u,
				0u
			)
		],
		std::string(
			"00"
		)
	);

	BOOST_CHECK_EQUAL(
		result[
			string_grid::pos(
				1u,
				2u
			)
		],
		std::string(
			"33"
		)
	);


	BOOST_REQUIRE_EQUAL(
		fcppt::container::grid::apply(
			function,
			grid1,
			string_grid()
		).size(),
		string_grid::dim(
			0u,
			0u
		)
	);
}
