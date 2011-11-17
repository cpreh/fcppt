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
	empty_optional
)
{
	typedef fcppt::optional<
		int
	> optional_int;

	optional_int const test(
		fcppt::empty_optional()
	);

	BOOST_REQUIRE(
		!test.has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_ref
)
{
	typedef fcppt::optional<
		int &
	> optional_int_ref;

	optional_int_ref test;

	BOOST_CHECK(
		!test.has_value()
	);

	int val = 42;

	test = val;

	BOOST_CHECK(
		test.has_value()
	);

	BOOST_CHECK(
		*test == 42
	);

	test.reset();

	BOOST_CHECK(
		!test.has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_ref_const
)
{
	typedef fcppt::optional<
		int const &
	> optional_int_ref_const;

	optional_int_ref_const test;

	BOOST_CHECK(
		!test.has_value()
	);

	int const val1 = 42;

	test = val1;

	BOOST_CHECK(
		test.has_value()
	);

	BOOST_CHECK(
		*test == 42
	);

	int val2 = 50;

	test = val2;

	BOOST_CHECK(
		test.has_value()
	);

	BOOST_CHECK(
		*test == 50
	);

	test.reset();

	BOOST_CHECK(
		!test.has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_ref_to_const_ref
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

	opt_ref = val;

	const_opt_ref = opt_ref;

	BOOST_CHECK(
		const_opt_ref.has_value()
	);

	BOOST_CHECK(
		&*const_opt_ref == &val
	);
}
