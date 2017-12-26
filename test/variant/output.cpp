//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_output
)
{
	typedef
	fcppt::variant::variadic<
		int
	>
	variant;

	fcppt::io::ostringstream stream;

	stream <<
		variant{
			42
		};

	BOOST_CHECK(
		stream.str()
		==
		fcppt::string{
			FCPPT_TEXT("42")
		}
	);
}
