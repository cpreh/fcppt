//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/map_concat.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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
	"algorithm map_concat"
	"[algorithm_map_concat]"
)
{
	CHECK(
		fcppt::algorithm::map_concat<
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
					int_vector{
						_value.value(),
						_value.value() + 5
					};
			}
		)
		==
		int_vector{
			1,
			6,
			2,
			7
		}
	);
}

TEST_CASE(
	"algorithm_map_concat move",
	"[algorithm_map_concat]"
)
{
	int_vector const ints{
		1,
		2
	};

	CHECK(
		fcppt::algorithm::map_concat<
			int_movable_vector
		>(
			ints,
			[](
				int const _value
			)
			{
				return
					fcppt::container::make<
						int_movable_vector
					>(
						int_movable{
							_value
						},
						int_movable{
							_value + 5
						}
					);
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
				6
			},
			int_movable{
				2
			},
			int_movable{
				7
			}
		)
	);
}
