//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const_optional_cast.hpp>
#include <fcppt/dynamic_optional_cast.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/optional_ref_compare.hpp>
#include <fcppt/static_optional_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::optional<
	int
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_general
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		std::string
	> optional_string;

	optional_string test;

	BOOST_REQUIRE(
		!test
	);

	BOOST_REQUIRE(
		!test.has_value()
	);

	test = "test";

	BOOST_REQUIRE(
		test
	);

	BOOST_REQUIRE(
		test.has_value()
	);

	BOOST_REQUIRE(
		test.get_unsafe() == "test"
	);

	test.reset();

	BOOST_REQUIRE(
		!test
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_comparison
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref
)
{
FCPPT_PP_POP_WARNING

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
		test2.get_unsafe() == 42
	);

	test2 = test1;

	BOOST_CHECK(
		!test2.has_value()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref_const
)
{
FCPPT_PP_POP_WARNING

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
		test2.get_unsafe() == 42
	);

	int val2 = 50;

	optional_int_ref_const test3(
		val2
	);

	BOOST_CHECK(
		test3.has_value()
	);

	BOOST_CHECK(
		test3.get_unsafe() == 50
	);

	test3 = test1;

	BOOST_CHECK(
		!test3.has_value()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref_conversions
)
{
FCPPT_PP_POP_WARNING
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
		&const_opt_ref.get_unsafe() == &val
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
		opt3.get_unsafe() == 42
	);

	BOOST_CHECK(
		opt4.get_unsafe() == 42
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_types
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		int
	> optional_int;

	BOOST_CHECK((
		std::is_same<
			optional_int::value_type,
			int
		>::value
	));

	BOOST_CHECK((
		std::is_same<
			optional_int::reference,
			int &
		>::value
	));

	BOOST_CHECK((
		std::is_same<
			optional_int::const_reference,
			int const &
		>::value
	));

	typedef fcppt::optional<
		int &
	> optional_int_ref;

	BOOST_CHECK((
		std::is_same<
			optional_int_ref::value_type,
			int
		>::value
	));

	BOOST_CHECK((
		std::is_same<
			optional_int_ref::reference,
			int &
		>::value
	));

	typedef fcppt::optional<
		int const &
	> optional_const_int_ref;

	BOOST_CHECK((
		std::is_same<
			optional_const_int_ref::value_type,
			int
		>::value
	));

	BOOST_CHECK((
		std::is_same<
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_dynamic_cast
)
{
FCPPT_PP_POP_WARNING

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
		&derived_ref.get_unsafe()
		== &derived_object
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_static_cast
)
{
FCPPT_PP_POP_WARNING

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
		&derived_ref.get_unsafe()
		== &derived_object
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_const_cast
)
{
FCPPT_PP_POP_WARNING

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
		&nonconst_ref.get_unsafe()
		== &object
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref_compare
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		int &
	> optional_int_ref;

	int a = 0;

	int b = 0;

	optional_int_ref const opt_a(
		a
	);

	optional_int_ref const opt_b(
		b
	);

	BOOST_CHECK(
		fcppt::optional_ref_compare(
			opt_a,
			optional_int_ref(
				a
			)
		)
	);

	BOOST_CHECK(
		!fcppt::optional_ref_compare(
			opt_a,
			opt_b
		)
	);

	BOOST_CHECK(
		!fcppt::optional_ref_compare(
			opt_a,
			optional_int_ref()
		)
	);
}

namespace
{

class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	explicit
	movable(
		std::string const &_value
	)
	:
		value_(
			_value
		)
	{
	}

	movable(
		movable &&
	) = default;

	movable &
	operator=(
		movable &&
	) = default;

	~movable()
	{
	}

	std::string const &
	value() const
	{
		return value_;
	}
private:
	std::string value_;
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_move
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		movable
	> optional_movable;


	optional_movable opta(
		movable(
			"test"
		)
	);

	optional_movable optb(
		std::move(
			opta
		)
	);

	BOOST_REQUIRE(
		!opta.has_value()
	);

	BOOST_REQUIRE(
		optb.has_value()
	);

	BOOST_CHECK(
		optb.get_unsafe().value()
		==
		"test"
	);

	optional_movable optc(
		movable(
			"test2"
		)
	);

	optc =
		std::move(
			optb
		);

	BOOST_REQUIRE(
		optc.has_value()
	);

	BOOST_REQUIRE(
		optb.has_value()
	);

	BOOST_CHECK(
		optc.get_unsafe().value()
		==
		"test"
	);

	BOOST_CHECK(
		optb.get_unsafe().value()
		==
		"test2"
	);

	optional_movable optd;

	optd =
		movable(
			"test3"
		);

	BOOST_CHECK(
		optd.get_unsafe().value()
		==
		"test3"
	);

	optd =
		movable(
			"test4"
		);

	BOOST_CHECK(
		optd.get_unsafe().value()
		==
		"test4"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_less
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		int
	> optional_int;

	BOOST_CHECK(
		!(
			optional_int()
			<
			optional_int()
		)
	);

	BOOST_CHECK(
		optional_int()
		<
		optional_int(
			10
		)
	);

	BOOST_CHECK(
		!(
			optional_int(
				10
			)
			<
			optional_int()
		)
	);

	BOOST_CHECK(
		optional_int(
			5
		)
		<
		optional_int(
			10
		)
	);

	BOOST_CHECK(
		!(
			optional_int(
				10
			)
			<
			optional_int(
				5
			)
		)
	);
}
