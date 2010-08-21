//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(unique_ptr)
{
	typedef fcppt::unique_ptr<
		int
	> int_ptr;

	int_ptr test1(
		new int(42)
	);

	int_ptr test2(
		fcppt::make_unique_ptr<
			int
		>(43)
	);

	BOOST_REQUIRE(
		*test1 == 42
	);

	BOOST_REQUIRE(
		*test2 == 43
	);

	test1 = fcppt::move(test2);

	BOOST_REQUIRE(
		!test2
	);

	BOOST_REQUIRE(
		*test1 == 43
	);
}
