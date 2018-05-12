//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/join.hpp>
#include <fcppt/assign/make_container.hpp>
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
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const result(
		fcppt::algorithm::join(
			fcppt::assign::make_container<
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
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					3
				),
				fcppt::make_unique_ptr<
					int
				>(
					4
				)
			),
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					5
				),
				fcppt::make_unique_ptr<
					int
				>(
					6
				)
			)
		)
	);

	REQUIRE(
		result.size()
		==
		6u
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

	CHECK(
		*result[2]
		==
		3
	);

	CHECK(
		*result[3]
		==
		4
	);

	CHECK(
		*result[4]
		==
		5
	);

	CHECK(
		*result[5]
		==
		6
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
