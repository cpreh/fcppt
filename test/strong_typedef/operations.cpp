//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_operators.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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

TEST_CASE(
	"strong_typedef arithmetic",
	"[strongtypedef]"
)
{
	strong_int test1(
		2
	);

	strong_int test2(
		4
	);

	CHECK(
		test1 + test2
		==
		strong_int(6)
	);

	CHECK(
		test2 - test1
		==
		strong_int(2)
	);

	CHECK(
		test1 * test2
		==
		strong_int(8)
	);

	CHECK(
		-test1
		==
		strong_int(-2)
	);

	CHECK(
		test1++
		==
		strong_int(2)
	);

	REQUIRE(
		test1
		==
		strong_int(3)
	);

	REQUIRE(
		test1--
		==
		strong_int(3)
	);

	REQUIRE(
		test1
		==
		strong_int(2)
	);

	REQUIRE(
		++test1
		==
		strong_int(3)
	);

	REQUIRE(
		--test1
		==
		strong_int(2)
	);
}

TEST_CASE(
	"strong_typedef assignment arithmetic",
	"[strongtypedef]"
)
{
	strong_int test(
		1
	);

	test += strong_int(2);

	REQUIRE(
		test
		==
		strong_int(3)
	);

	test -= strong_int(1);

	REQUIRE(
		test
		==
		strong_int(2)
	);

	test *= strong_int(2);

	REQUIRE(
		test
		==
		strong_int(4)
	);
}

TEST_CASE(
	"strong_typedef assignment bitwise",
	"[strongtypedef]"
)
{
	strong_uint test1{
		3U
	};

	test1 &= strong_uint{2U};

	REQUIRE(
		test1
		==
		strong_uint{2U}
	);

	test1 |= strong_uint{3U};

	REQUIRE(
		test1
		==
		strong_uint{3U}
	);

	test1 ^= strong_uint{2U};

	REQUIRE(
		test1
		==
		strong_uint{1U}
	);
}

TEST_CASE(
	"strong_typedef bitwise",
	"[strongtypedef]"
)
{
	strong_uint const test1(
		2U
	);

	strong_uint const test2(
		3U
	);

	CHECK(
		(
			test1
			&
			test2
		)
		==
		strong_uint{2U}
	);

	CHECK(
		(
			test1
			|
			test2
		)
		==
		strong_uint{3U}
	);

	CHECK(
		(
			test1
			^
			test2
		)
		==
		strong_uint{1U}
	);

	CHECK(
		~test1
		==
		strong_uint{
			~2U
		}
	);
}

TEST_CASE(
	"strong_typedef comparison",
	"[strongtypedef]"
)
{
	strong_int const test1(
		1
	);

	strong_int const test2(
		1
	);

	strong_int const test3(
		2
	);

	CHECK(
		test1
		==
		test2
	);

	CHECK(
		test1
		!=
		test3
	);

	CHECK(
		test1
		<=
		test2
	);

	CHECK(
		test1
		>=
		test2
	);

	CHECK(
		test1
		<
		test3
	);

	CHECK(
		test3
		>
		test1
	);
}
