//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/array/binary_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <utility>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	array_binar_map
)
{
	typedef
	std::array<
		int,
		2
	>
	int_2_array;

	typedef
	std::array<
		int,
		2
	>
	bool_2_array;

	typedef
	std::array<
		std::pair<
			int,
			bool
		>,
		2
	>
	result_array;

	result_array const result(
		fcppt::container::array::binary_map(
			int_2_array{{
				1,
				2
			}},
			bool_2_array{{
				true,
				false
			}},
			[](
				int const _value1,
				bool const _value2
			)
			{
				return
					std::make_pair(
						_value1,
						_value2
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		).first,
		1
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		).second,
		true
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		).first,
		2
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		).second,
		false
	);
}

BOOST_AUTO_TEST_CASE(
	array_binary_map_move
)
{
	typedef
	std::array<
		fcppt::unique_ptr<
			int
		>,
		1
	>
	int_1_array;

	typedef
	std::array<
		std::pair<
			fcppt::unique_ptr<
				int
			>,
			fcppt::unique_ptr<
				int
			>
		>,
		1
	>
	result_array;

	result_array const result(
		fcppt::container::array::binary_map(
			int_1_array{{
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			}},
			int_1_array{{
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			}},
			[](
				fcppt::unique_ptr<
					int
				> &&_arg1,
				fcppt::unique_ptr<
					int
				> &&_arg2
			)
			{
				return
					std::make_pair(
						std::move(
							_arg1
						),
						std::move(
							_arg2
						)
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).first,
		1
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).second,
		2
	);
}
