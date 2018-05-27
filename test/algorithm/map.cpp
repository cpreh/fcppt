//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop_break_brigand.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <array>
#include <catch.hpp>
#include <string>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

typedef
std::vector<
	int
>
int_vector;

typedef
std::vector<
	int_unique_ptr
>
int_unique_ptr_vector;

}

TEST_CASE(
	"algorithm_map"
	"[algorithm_map]"
)
{
	CHECK(
		fcppt::algorithm::map<
			int_vector
		>(
			fcppt::container::make<
				int_unique_ptr_vector
			>(
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
			),
			[](
				int_unique_ptr const &_value
			)
			{
				return
					*_value;
			}
		)
		==
		int_vector{
			1,
			2
		}
	);
}

TEST_CASE(
	"algorithm_map move"
	"[algorithm_map]"
)
{
	int_vector const ints{
		1,
		2
	};

	int_unique_ptr_vector const result(
		fcppt::algorithm::map<
			int_unique_ptr_vector
		>(
			ints,
			[](
				int const _value
			)
			{
				return
					fcppt::make_unique_ptr<
						int
					>(
						_value
					);
			}
		)
	);

	REQUIRE(
		result.size()
		==
		ints.size()
	);

	CHECK(
		*result[0]
		==
		1
	);

	CHECK(
		*result[1]
		==
		2
	);
}

TEST_CASE(
	"algorithm_map brigand",
	"[algorithm_map]"
)
{
	CHECK(
		fcppt::algorithm::map<
			int_vector
		>(
			brigand::list<
				std::integral_constant<
					int,
					1
				>,
				std::integral_constant<
					int,
					2
				>
			>{},
			[](
				auto const _value
			)
			{
				FCPPT_USE(
					_value
				);

				typedef
				fcppt::tag_type<
					decltype(
						_value
					)
				>
				type;

				return
					type::value;
			}
		)
		==
		int_vector{
			1,
			2
		}
	);
}

TEST_CASE(
	"algorithm_map array",
	"[algorithm_map]"
)
{
	typedef
	std::array<
		std::string,
		2
	>
	string_2_array;

	CHECK(
		fcppt::algorithm::map<
			string_2_array
		>(
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
			-> std::string
			{
				return
					fcppt::insert_to_std_string(
						_value
					);
			}
		)
		==
		string_2_array{
			"1",
			"2"
		}
	);
}

TEST_CASE(
	"algorithm_map array move",
	"[algorithm_map]"
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		int_unique_ptr,
		strong_ptr
	);

	typedef
	std::array<
		int_unique_ptr,
		2
	>
	source_array;

	typedef
	std::array<
		strong_ptr,
		2
	>
	dest_array;

	dest_array const result(
		fcppt::algorithm::map<
			dest_array
		>(
			source_array{{
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
				int_unique_ptr &&_value
			)
			-> strong_ptr
			{
				return
					strong_ptr{
						std::move(
							_value
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
