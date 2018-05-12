//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/map_concat.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
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
	"algorithm map_concat"
	"[algorithm_map_concat]"
)
{
	CHECK(
		fcppt::algorithm::map_concat<
			int_vector
		>(
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
			[](
				int_unique_ptr const &_value
			)
			{
				return
					int_vector{
						*_value,
						*_value + 5
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

	int_unique_ptr_vector const result(
		fcppt::algorithm::map_concat<
			int_unique_ptr_vector
		>(
			ints,
			[](
				int const _value
			)
			{
				return
					fcppt::assign::make_container<
						int_unique_ptr_vector
					>(
						fcppt::make_unique_ptr<
							int
						>(
							_value
						),
						fcppt::make_unique_ptr<
							int
						>(
							_value + 5
						)
					);
			}
		)
	);

	REQUIRE(
		result.size()
		==
		4u
	);

	CHECK(
		*result[0]
		==
		1
	);

	CHECK(
		*result[1]
		==
		6
	);

	CHECK(
		*result[2]
		==
		2
	);

	CHECK(
		*result[3]
		==
		7
	);
}
