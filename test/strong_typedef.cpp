//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

FCPPT_MAKE_STRONG_TYPEDEF(
	int &,
	strong_int_ref
);

FCPPT_MAKE_STRONG_TYPEDEF(
	int const &,
	strong_int_const_ref
);

}

BOOST_AUTO_TEST_CASE(
	strong_typedef_arithmetic
)
{
	strong_int
		test1(
			2
		),
		test2(
			4
		);

	BOOST_REQUIRE(
		test1 + test2
		== strong_int(6)
	);

	BOOST_REQUIRE(
		test2 - test1
		== strong_int(2)
	);

	BOOST_REQUIRE(
		test1 * test2
		== strong_int(8)
	);

	BOOST_REQUIRE(
		test2 / test1
		== strong_int(2)
	);

	BOOST_REQUIRE(
		test2 % test1
		== strong_int(0)
	);

	BOOST_REQUIRE(
		+test1
		== strong_int(2)
	);

	BOOST_REQUIRE(
		-test1
		== strong_int(-2)
	);

	BOOST_REQUIRE(
		test1++
		== strong_int(2)
	);

	BOOST_REQUIRE(
		test1
		== strong_int(3)
	);

	BOOST_REQUIRE(
		test1--
		== strong_int(3)
	);

	BOOST_REQUIRE(
		test1
		== strong_int(2)
	);

	BOOST_REQUIRE(
		++test1
		== strong_int(3)
	);

	BOOST_REQUIRE(
		--test1
		== strong_int(2)
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_assignment
)
{
	strong_int test(
		1
	);

	test += strong_int(2);

	BOOST_REQUIRE(
		test
		== strong_int(3)
	);

	test -= strong_int(1);

	BOOST_REQUIRE(
		test
		== strong_int(2)
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_comparison
)
{
	strong_int const
		test1(
			1
		),
		test2(
			1
		),
		test3(
			2
		);

	BOOST_REQUIRE(
		test1 == test2
	);

	BOOST_REQUIRE(
		test1 != test3
	);

	BOOST_REQUIRE(
		test1 <= test2
	);

	BOOST_REQUIRE(
		test1 >= test2
	);

	BOOST_REQUIRE(
		test1 < test3
	);

	BOOST_REQUIRE(
		test3 > test1
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_io
)
{
	std::stringstream stream;

	strong_int const test(
		42
	);

	stream << test;

	strong_int result;

	BOOST_REQUIRE(
		stream >> result
	);

	BOOST_REQUIRE(
		test == result
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_const_reference
)
{
	int const test(
		42
	);

	strong_int_const_ref const int_ref(
		test
	);

	BOOST_REQUIRE(
		&int_ref.get()
		== &test
	);

	BOOST_REQUIRE(
		int_ref.get()
		== test
	);
}

/*
BOOST_AUTO_TEST_CASE(
	strong_typedef_reference
)
{
	int test(
		42
	);

	strong_int_ref const int_ref(
		test
	);

	BOOST_REQUIRE(
		&int_ref.get()
		== &test
	);

	BOOST_REQUIRE(
		int_ref.get()
		== test
	);
}
*/
