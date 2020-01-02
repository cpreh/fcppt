//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::container::buffer::object<
	int
>
container_type;

}

template
class
fcppt::container::buffer::object<
	int
>;

TEST_CASE(
	"container::buffer::object",
	"[container],[buffer]"
)
{
	container_type test1{
		5u
	};

	REQUIRE(
		test1.read_size()
		==
		0u
	);

	REQUIRE(
		test1.write_size()
		==
		5u
	);

	*test1.write_data() =
		10;

	test1.written(
		1u
	);

	REQUIRE(
		test1.read_size()
		==
		1u
	);

	REQUIRE(
		test1.write_size()
		==
		4u
	);

	CHECK(
		test1[
			0
		]
		==
		10
	);
}

TEST_CASE(
	"container::buffer move",
	"[container],[buffer]"
)
{
	container_type test1{
		100u
	};

	*test1.write_data() =
		42;

	test1.written(
		1u
	);

	container_type test2(
		std::move(
			test1
		)
	);

	REQUIRE(
		test2.write_size()
		==
		99u
	);

	CHECK(
		test2[
			0
		]
		==
		42
	);

	container_type test3{
		0u
	};

	test3 =
		std::move(
			test2
		);

	REQUIRE(
		test3.write_size()
		==
		99u
	);

	CHECK(
		test3[
			0
		]
		==
		42
	);
}

TEST_CASE(
	"container::buffer resize_write_area",
	"[container],[buffer]"
)
{
	container_type container{
		2u
	};

	container.write_data()[0] = 10;

	container.written(
		1u
	);

	CHECK(
		container.read_size()
		==
		1u
	);

	CHECK(
		container.write_size()
		==
		1u
	);

	container.resize_write_area(
		3u
	);

	CHECK(
		container.write_size()
		==
		3u
	);

	REQUIRE(
		container.read_size()
		==
		1u
	);

	CHECK(
		container[0]
		==
		10
	);
}
