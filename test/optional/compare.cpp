//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/object.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_comparison
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional::object<
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
	optional_less
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional::object<
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
