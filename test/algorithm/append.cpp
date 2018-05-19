//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/algorithm/append.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"append with copy",
	"[algorithm]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector ints{
		1,2,3
	};

	fcppt::algorithm::append(
		ints,
		int_vector{
			4,5,6
		}
	);

	int_vector const result{
		1,2,3,4,5,6
	};

	CHECK(
		ints
		==
		result
	);
}

TEST_CASE(
	"append with move",
	"[algorithm]"
)
{
	typedef
	std::vector<
		fcppt::unique_ptr<
			int
		>
	>
	int_ptr_vector;

	int_ptr_vector ints;

	ints.push_back(
		fcppt::make_unique_ptr<
			int
		>(
			1
		)
	);

	ints.push_back(
		fcppt::make_unique_ptr<
			int
		>(
			2
		)
	);

	fcppt::algorithm::append(
		ints,
		[]{
			int_ptr_vector new_ints;

			new_ints.push_back(
				fcppt::make_unique_ptr<
					int
				>(
					3
				)
			);

			new_ints.push_back(
				fcppt::make_unique_ptr<
					int
				>(
					4
				)
			);

			return
				new_ints;
		}()
	);

	REQUIRE(
		ints.size()
		==
		4u
	);

	CHECK(
		*ints[0]
		==
		1
	);

	CHECK(
		*ints[1]
		==
		2
	);

	CHECK(
		*ints[2]
		==
		3
	);

	CHECK(
		*ints[3]
		==
		4
	);
}
