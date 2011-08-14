//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/assert.hpp>
#include <fcppt/text.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
bool
contains_false(
	fcppt::assert_::exception const &_e)
{
	return
		_e.string().find(
			FCPPT_TEXT("false")) != fcppt::string::npos;
}

bool
contains_false_and_contains_1337(
	fcppt::assert_::exception const &_e)
{
	return
		contains_false(
			_e) &&
		_e.string().find(
			FCPPT_TEXT("1337")) != fcppt::string::npos;
}
}

BOOST_AUTO_TEST_CASE(
	assert
)
{
	BOOST_REQUIRE_EXCEPTION(
		FCPPT_ASSERT_THROW_MESSAGE(
			false,
			fcppt::assert_::exception,
			FCPPT_TEXT("test")
		),
		fcppt::assert_::exception,
		contains_false
	);

	BOOST_REQUIRE_EXCEPTION(
		FCPPT_ASSERT_THROW_MESSAGE(
			false,
			fcppt::assert_::exception,
			FCPPT_TEXT("1337")
		),
		fcppt::assert_::exception,
		contains_false_and_contains_1337
	);
}
