//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/insert_to_std_string_convert.hpp>
#include <fcppt/insert_to_std_wstring.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	insert_to_string
)
{
	BOOST_CHECK(
		fcppt::insert_to_fcppt_string(
			42
		)
		==
		FCPPT_TEXT("42")
	);

	BOOST_CHECK_EQUAL(
		fcppt::insert_to_std_string(
			42
		),
		"42"
	);

	BOOST_CHECK(
		fcppt::insert_to_std_wstring(
			42
		)
		==
		L"42"
	);

	BOOST_CHECK(
		fcppt::insert_to_std_string_convert(
			42
		)
		==
		"42"
	);
}
