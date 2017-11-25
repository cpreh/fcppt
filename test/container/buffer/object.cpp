//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
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

BOOST_AUTO_TEST_CASE(
	container_buffer_object
)
{
	container_type test1{
		5u
	};

	BOOST_REQUIRE_EQUAL(
		test1.read_size(),
		0u
	);

	BOOST_REQUIRE_EQUAL(
		test1.write_size(),
		5u
	);

	*test1.write_data() =
		10;

	test1.written(
		1u
	);

	BOOST_REQUIRE_EQUAL(
		test1.read_size(),
		1u
	);

	BOOST_REQUIRE_EQUAL(
		test1.write_size(),
		4u
	);

	BOOST_CHECK_EQUAL(
		test1[
			0
		],
		10
	);
}

BOOST_AUTO_TEST_CASE(
	container_buffer_move
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

	BOOST_REQUIRE_EQUAL(
		test2.write_size(),
		99u
	);

	BOOST_CHECK_EQUAL(
		test2[
			0
		],
		42
	);

	BOOST_REQUIRE(
		test1.write_data()
		==
		test1.write_data_end()
	);

	BOOST_REQUIRE(
		test1.read_data()
		==
		test1.read_data_end()
	);

	container_type test3{
		0u
	};

	test3 =
		std::move(
			test2
		);

	BOOST_REQUIRE_EQUAL(
		test3.write_size(),
		99u
	);

	BOOST_CHECK_EQUAL(
		test3[
			0
		],
		42
	);

	BOOST_REQUIRE(
		test2.write_data()
		==
		test2.write_data_end()
	);

	BOOST_REQUIRE(
		test2.read_data()
		==
		test2.read_data_end()
	);
}

BOOST_AUTO_TEST_CASE(
	container_buffer_resize_write_area
)
{
	container_type container{
		2u
	};

	container.write_data()[0] = 10;

	container.written(
		1u
	);

	BOOST_CHECK_EQUAL(
		container.read_size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		container.write_size(),
		1u
	);

	container.resize_write_area(
		3u
	);

	BOOST_CHECK_EQUAL(
		container.read_size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		container.write_size(),
		3u
	);

	BOOST_CHECK_EQUAL(
		container[0],
		10
	);
}
