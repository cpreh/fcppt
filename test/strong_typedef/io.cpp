//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_input.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

BOOST_AUTO_TEST_CASE(
	strong_typedef_io
)
{
	{
		std::stringstream stream;

		strong_int const test(
			42
		);

		stream << test;

		strong_int result(
			0
		);

		BOOST_REQUIRE(
			stream >> result
		);

		BOOST_CHECK_EQUAL(
			test,
			result
		);
	}

	{
		std::stringstream stream;

		stream << 42;

		fcppt::optional::object<
			strong_int
		> const result2{
			fcppt::io::extract<
				strong_int
			>(
				stream
			)
		};

		BOOST_CHECK_EQUAL(
			fcppt::optional::make(
				strong_int{
					42
				}
			),
			result2
		);
	}
}
