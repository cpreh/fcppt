//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	either_failure_opt
)
{
	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	BOOST_CHECK_EQUAL(
		fcppt::either::failure_opt(
			either_int(
				std::string(
					"test"
				)
			)
		),
		optional_string(
			std::string(
				"test"
			)
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::failure_opt(
			either_int(
				42
			)
		),
		optional_string()
	);
}
