//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

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

BOOST_AUTO_TEST_CASE(
	optional_ref
)
{
	typedef fcppt::optional<
		int &
	> optional_int_ref;

	optional_int_ref test1;

	BOOST_CHECK(
		!test1.has_value()
	);

	int val = 42;

	optional_int_ref test2(
		val
	);

	BOOST_CHECK(
		test2.has_value()
	);

	BOOST_CHECK(
		*test2 == 42
	);

	test2 = test1;

	BOOST_CHECK(
		!test2.has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_ref_const
)
{
	typedef fcppt::optional<
		int const &
	> optional_int_ref_const;

	optional_int_ref_const test1;

	BOOST_CHECK(
		!test1.has_value()
	);

	int const val1 = 42;

	optional_int_ref_const test2(
		val1
	);

	BOOST_CHECK(
		test2.has_value()
	);

	BOOST_CHECK(
		*test2 == 42
	);

	int val2 = 50;

	optional_int_ref_const test3(
		val2
	);

	BOOST_CHECK(
		test3.has_value()
	);

	BOOST_CHECK(
		*test3 == 50
	);

	test3 = test1;

	BOOST_CHECK(
		!test3.has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_ref_conversions
)
{
	typedef fcppt::optional<
		int &
	> optional_int_ref;

	optional_int_ref opt_ref;

	typedef fcppt::optional<
		int const &
	> optional_int_ref_const;

	optional_int_ref_const const_opt_ref(
		opt_ref
	);

	BOOST_CHECK(
		!const_opt_ref
	);

	int val(42);

	opt_ref =
		optional_int_ref(
			val
		);

	const_opt_ref =
		optional_int_ref_const(
			opt_ref
		);

	BOOST_CHECK(
		const_opt_ref.has_value()
	);

	BOOST_CHECK(
		&*const_opt_ref == &val
	);

	typedef fcppt::optional<
		int
	> optional_int;

	optional_int const opt3(
		opt_ref
	);

	optional_int const opt4(
		const_opt_ref
	);

	BOOST_CHECK(
		*opt3 == 42
	);

	BOOST_CHECK(
		*opt4 == 42
	);
}
