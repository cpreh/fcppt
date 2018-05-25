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
#include <array>
#include <catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::map",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::map(
			std::array<
				int,
				2
			>{{
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
		==
		std::array<
			std::string,
			2
		>{{
			std::string{
				"1"
			},
			std::string{
				"2"
			}
		}}
	);
}

TEST_CASE(
	"array::map move",
	"[container],[array]"
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

	CHECK(
		*std::get<
			0
		>(
			result
		).get()
		==
		1
	);

	CHECK(
		*std::get<
			1
		>(
			result
		).get()
		==
		2
	);
}
