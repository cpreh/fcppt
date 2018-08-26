//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::raw_vector comparison",
	"[container],[raw_vector]"
)
{
	typedef
	fcppt::container::raw_vector::object<
		int
	>
	int_vector;

	int_vector const test1{
		1,
		2
	};

	int_vector const test2{
		2,
		3
	};

	int_vector const test3{
		1,
		2
	};

	CHECK(
		test1
		==
		test3
	);

	CHECK(
		test1
		!=
		test2
	);

	CHECK(
		test1
		<
		test2
	);

	CHECK(
		test2
		>
		test1
	);
}
