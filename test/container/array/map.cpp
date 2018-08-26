//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <catch2/catch.hpp>
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
					fcppt::output_to_std_string(
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
	fcppt::catch_::movable<
		int
	>
	int_movable;

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_movable,
		strong_int_movable
	);

	CHECK(
		fcppt::container::array::map(
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
				int_movable &&_arg
			)
			{
				return
					strong_int_movable{
						std::move(
							_arg
						)
					};
			}
		)
		==
		std::array<
			strong_int_movable,
			2
		>{{
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
