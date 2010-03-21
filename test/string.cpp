//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/narrow.hpp>
#include <fcppt/widen.hpp>
#include <string>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(string_convert)
{
	std::wstring const test(
		L"localhöst 東方"
	);

	std::string const narrow(
		fcppt::narrow(
			test
		)
	);

	std::wstring const back(
		fcppt::widen(
			narrow
		)
	);

	BOOST_REQUIRE(
		back == test
	);
}
