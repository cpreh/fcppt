//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/extract.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	io_extract
)
{
	{
		std::istringstream stream(
			"xy"
		);

		BOOST_CHECK_EQUAL(
			fcppt::io::extract<
				int
			>(
				stream
			),
			fcppt::optional::object<
				int
			>{}
		);
	}

	{
		std::istringstream stream(
			"42"
		);

		BOOST_CHECK_EQUAL(
			fcppt::io::extract<
				int
			>(
				stream
			),
			fcppt::optional::make(
				42
			)
		);
	}
}
