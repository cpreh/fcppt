//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <boost/test/unit_test.hpp>

template class
fcppt::optional<
	int
>;

BOOST_AUTO_TEST_CASE(
	optional
)
{
	typedef fcppt::optional<
		int
	> optional_int;

	optional_int test;

	BOOST_REQUIRE(
		!test
	);

	BOOST_REQUIRE(
		!test.has_value()
	);

	test = 42;

	BOOST_REQUIRE(
		test
	);

	BOOST_REQUIRE(
		test.has_value()
	);

	BOOST_REQUIRE(
		*test == 42
	);

	test.reset();

	BOOST_REQUIRE(
		!test
	);
}

BOOST_AUTO_TEST_CASE(
	optional_comparison
)
{
	typedef fcppt::optional<
		int
	> optional_int;

	optional_int const test1(
		1
	);

	optional_int const test2(
		2
	);

	optional_int const test3;

	BOOST_CHECK(
		test1 != test2
	);

	BOOST_CHECK(
		test2 != test1
	);

	BOOST_CHECK(
		test1 == test1
	);

	BOOST_CHECK(
		test1 != test3
	);

	BOOST_CHECK(
		test3 != test1
	);

	BOOST_CHECK(
		test3 == test3
	);
}
