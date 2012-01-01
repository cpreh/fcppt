//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/stream_to_string.hpp>
#include <fcppt/io/stream_to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	io_stream_to_string
)
{
	std::istringstream istream(
		"TEST abcd"
	);

	std::string const result(
		fcppt::io::stream_to_string(
			istream
		)
	);

	BOOST_CHECK(
		result == "TEST abcd"
	);
}
