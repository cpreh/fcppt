//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/expect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	io_expect
)
{
	std::istringstream stream(
		"xy"
	);

	fcppt::io::expect(
		stream,
		'x'
	);

	BOOST_CHECK(
		stream
	);

	fcppt::io::expect(
		stream,
		'x'
	);

	BOOST_CHECK(
		!stream
	);
}
