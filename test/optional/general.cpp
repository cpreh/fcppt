//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <type_traits>
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
		!test.has_value()
	);

	test =
		optional_string(
			"test"
		);

	BOOST_REQUIRE(
		test.has_value()
	);

	BOOST_REQUIRE(
		test.get_unsafe() == "test"
	);

	test =
		optional_string();

	BOOST_REQUIRE(
		!test.has_value()
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
