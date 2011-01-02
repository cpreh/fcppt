//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/array.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <string>

template struct fcppt::container::array<
	int,
	5
>;

template struct fcppt::container::array<
	int,
	0
>;

BOOST_AUTO_TEST_CASE(
	array_fundamental
)
{
	fcppt::container::array<
		int,
		10
	> array;

	BOOST_REQUIRE(
		array.size() == 10
	);

	array.fill(42);

	BOOST_REQUIRE(
		std::count(
			array.begin(),
			array.end(),
			42
		)
		== 10
	);
}

BOOST_AUTO_TEST_CASE(
	array_string
)
{
	fcppt::container::array<
		std::string,
		3
	> array;

	BOOST_REQUIRE(
		array.size() == 3
	);

	array[0] = "foo";
	array[1] = "bar";
	array[2] = "baz";

	BOOST_REQUIRE(
		array[0] == "foo"
		&& array[1] == "bar"
		&& array[2] == "baz"
	);
}

BOOST_AUTO_TEST_CASE(
	array_empty
)
{
	fcppt::container::array<
		int,
		0
	> array;

	BOOST_REQUIRE(
		array.empty()
	);

	BOOST_REQUIRE(
		array.begin()
		== array.end()
	);

	BOOST_REQUIRE(
		array.data()
		== array.data_end()
	);
}
