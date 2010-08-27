//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(optional)
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
