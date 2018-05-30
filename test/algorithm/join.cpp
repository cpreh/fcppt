//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/join.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <map>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm_join std::vector"
	"[algorithm_join]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec3{
		5,
		6
	};

	CHECK(
		fcppt::algorithm::join(
			int_vector{
				1,
				2
			},
			int_vector{
				3,
				4
			},
			vec3
		)
		==
		int_vector{
			1,
			2,
			3,
			4,
			5,
			6
		}
	);
}

TEST_CASE(
	"algorithm_join move"
	"[algorithm_join]"
)
{
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

	CHECK(
		fcppt::algorithm::join(
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
			fcppt::container::make<
				int_movable_vector
			>(
				int_movable{
					3
				},
				int_movable{
					4
				}
			),
			fcppt::container::make<
				int_movable_vector
			>(
				int_movable{
					5
				},
				int_movable{
					6
				}
			)
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
			},
			int_movable{
				3
			},
			int_movable{
				4
			},
			int_movable{
				5
			},
			int_movable{
				6
			}
		)
	);
}

TEST_CASE(
	"algorithm_join std::map"
	"[algorithm_join]"
)
{
	typedef
	std::map<
		int,
		char
	>
	int_map;

	CHECK(
		fcppt::algorithm::join(
			int_map{
				std::make_pair(
					1,
					'a'
				),
				std::make_pair(
					2,
					'b'
				)
			},
			int_map{
				std::make_pair(
					2,
					'c'
				),
				std::make_pair(
					3,
					'd'
				)
			}
		)
		==
		int_map{
			std::make_pair(
				1,
				'a'
			),
			std::make_pair(
				2,
				'b'
			),
			std::make_pair(
				3,
				'd'
			)
		}
	);
}
