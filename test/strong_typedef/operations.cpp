//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_operators.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

FCPPT_MAKE_STRONG_TYPEDEF(
	unsigned,
	strong_uint
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

	BOOST_CHECK_EQUAL(
		test1 + test2,
		strong_int(6)
	);

	BOOST_CHECK_EQUAL(
		test2 - test1,
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		test1 * test2,
		strong_int(8)
	);

	BOOST_CHECK_EQUAL(
		-test1,
		strong_int(-2)
	);

	BOOST_CHECK_EQUAL(
		test1++,
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		test1,
		strong_int(3)
	);

	BOOST_CHECK_EQUAL(
		test1--,
		strong_int(3)
	);

	BOOST_CHECK_EQUAL(
		test1,
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		++test1,
		strong_int(3)
	);

	BOOST_CHECK_EQUAL(
		--test1,
		strong_int(2)
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_assignment_arithmetic
)
{
	strong_int test(
		1
	);

	test += strong_int(2);

	BOOST_CHECK_EQUAL(
		test,
		strong_int(3)
	);

	test -= strong_int(1);

	BOOST_CHECK_EQUAL(
		test,
		strong_int(2)
	);

	test *= strong_int(2);

	BOOST_CHECK_EQUAL(
		test,
		strong_int(4)
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_assignment_bitwise
)
{
	strong_uint test1{
		3u
	};

	test1 &= strong_uint{2u};

	BOOST_CHECK_EQUAL(
		test1,
		strong_uint{2u}
	);

	test1 |= strong_uint{3u};

	BOOST_CHECK_EQUAL(
		test1,
		strong_uint{3u}
	);

	test1 ^= strong_uint{2u};

	BOOST_CHECK_EQUAL(
		test1,
		strong_uint{1u}
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_bitwise
)
{
	strong_uint const
		test1(
			2u
		),
		test2(
			3u
		);

	BOOST_CHECK_EQUAL(
		test1
		&
		test2,
		strong_uint{2u}
	);

	BOOST_CHECK_EQUAL(
		test1
		|
		test2,
		strong_uint{3u}
	);

	BOOST_CHECK_EQUAL(
		test1
		^
		test2,
		strong_uint{1u}
	);

	BOOST_CHECK_EQUAL(
		~test1,
		strong_uint{
			~2u
		}
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

	BOOST_CHECK(
		test1 == test2
	);

	BOOST_CHECK(
		test1 != test3
	);

	BOOST_CHECK(
		test1 <= test2
	);

	BOOST_CHECK(
		test1 >= test2
	);

	BOOST_CHECK(
		test1 < test3
	);

	BOOST_CHECK(
		test3 > test1
	);
}
