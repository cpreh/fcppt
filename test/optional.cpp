//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/type_traits/is_same.hpp>
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

BOOST_AUTO_TEST_CASE(
	optional_types
)
{
	typedef fcppt::optional<
		int
	> optional_int;

	BOOST_CHECK((
		boost::is_same<
			optional_int::value_type,
			int
		>::value
	));

	BOOST_CHECK((
		boost::is_same<
			optional_int::reference,
			int &
		>::value
	));

	BOOST_CHECK((
		boost::is_same<
			optional_int::const_reference,
			int const &
		>::value
	));

	typedef fcppt::optional<
		int &
	> optional_int_ref;

	BOOST_CHECK((
		boost::is_same<
			optional_int_ref::value_type,
			int
		>::value
	));

	BOOST_CHECK((
		boost::is_same<
			optional_int_ref::reference,
			int &
		>::value
	));

	typedef fcppt::optional<
		int const &
	> optional_const_int_ref;

	BOOST_CHECK((
		boost::is_same<
			optional_const_int_ref::value_type,
			int
		>::value
	));

	BOOST_CHECK((
		boost::is_same<
			optional_const_int_ref::reference,
			int const &
		>::value
	));
}

namespace
{

struct base
{
	virtual ~base()
	{
	}
};

struct derived
:
	base
{
};

typedef fcppt::optional<
	base &
> optional_base_ref;

typedef fcppt::optional<
	derived &
> optional_derived_ref;

}

BOOST_AUTO_TEST_CASE(
	optional_dynamic_cast
)
{
	optional_base_ref empty_base;

	optional_derived_ref empty_derived(
		fcppt::dynamic_optional_cast<
			derived
		>(
			empty_base
		)
	);

	BOOST_CHECK(
		!empty_derived.has_value()
	);

	derived derived_object;

	optional_base_ref base_ref(
		derived_object
	);

	optional_derived_ref derived_ref(
		fcppt::dynamic_optional_cast<
			derived
		>(
			base_ref
		)
	);

	BOOST_CHECK(
		derived_ref.has_value()
	);

	BOOST_CHECK(
		&*derived_ref
		== &derived_object
	);
}

BOOST_AUTO_TEST_CASE(
	optional_static_cast
)
{
	optional_base_ref empty_base;

	optional_derived_ref empty_derived(
		fcppt::static_optional_cast<
			derived
		>(
			empty_base
		)
	);

	BOOST_CHECK(
		!empty_derived.has_value()
	);

	derived derived_object;

	optional_base_ref base_ref(
		derived_object
	);

	optional_derived_ref derived_ref(
		fcppt::static_optional_cast<
			derived
		>(
			base_ref
		)
	);

	BOOST_CHECK(
		derived_ref.has_value()
	);

	BOOST_CHECK(
		&*derived_ref
		== &derived_object
	);
}

BOOST_AUTO_TEST_CASE(
	optional_const_cast
)
{
	typedef fcppt::optional<
		base const &
	> optional_const_base_ref;

	base object;

	optional_const_base_ref const ref(
		object
	);

	optional_base_ref const nonconst_ref(
		fcppt::const_optional_cast<
			base
		>(
			ref
		)
	);

	BOOST_CHECK(
		nonconst_ref.has_value()
	);

	BOOST_CHECK(
		&*nonconst_ref
		== &object
	);
}
