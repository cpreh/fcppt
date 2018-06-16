//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop_break_brigand.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/catch/movable.hpp>
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
std::vector<
	int
>
int_vector;

typedef
fcppt::catch_::movable<
	int
>
int_movable;

typedef
std::vector<
	int_movable
>
int_movable_vector;

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
				int_movable_vector
			>(
				int_movable{
					1
				},
				int_movable{
					2
				}
			),
			[](
				int_movable const &_value
			)
			{
				return
					_value.value();
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
	CHECK(
		fcppt::algorithm::map<
			int_movable_vector
		>(
			int_vector{
				1,
				2
			},
			[](
				int const _value
			)
			{
				return
					int_movable{
						_value
					};
			}
		)
		==
		fcppt::container::make<
			int_movable_vector
		>(
			int_movable{
				1
			},
			int_movable{
				2
			}
		)
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
					fcppt::output_to_std_string(
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
		int_movable,
		strong_int_movable
	);

	typedef
	std::array<
		strong_int_movable,
		2
	>
	strong_int_movable_array;

	CHECK(
		fcppt::algorithm::map<
			strong_int_movable_array
		>(
			std::array<
				int_movable,
				2
			>{{
				int_movable{
					1
				},
				int_movable{
					2
				}
			}},
			[](
				int_movable &&_value
			)
			-> strong_int_movable
			{
				return
					strong_int_movable{
						std::move(
							_value
						)
					};
			}
		)
		==
		strong_int_movable_array{{
			strong_int_movable{
				int_movable{
					1
				}
			},
			strong_int_movable{
				int_movable{
					2
				}
			}
		}}
	);
}
