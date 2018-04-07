//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/array/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	array_map
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
		std::string,
		2
	>
	string_2_array;

	string_2_array const result(
		fcppt::container::array::map(
			int_2_array{{
				1,
				2
			}},
			[](
				int const _value
			)
			->
			std::string
			{
				return
					fcppt::insert_to_std_string(
						_value
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		),
		"1"
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		),
		"2"
	);
}

BOOST_AUTO_TEST_CASE(
	array_map_move
)
{
	typedef
	std::array<
		fcppt::unique_ptr<
			int
		>,
		2
	>
	int_2_array;

	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::unique_ptr<
			int
		>,
		strong_ptr
	);

	typedef
	std::array<
		strong_ptr,
		2
	>
	result_array;

	result_array const result(
		fcppt::container::array::map(
			int_2_array{{
				fcppt::make_unique_ptr<
					int
				>(
					1
				),
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			}},
			[](
				fcppt::unique_ptr<
					int
				> &&_arg
			)
			{
				return
					strong_ptr{
						std::move(
							_arg
						)
					};
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).get(),
		1
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			1
		>(
			result
		).get(),
		2
	);
}
