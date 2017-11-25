//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/bind.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	either_bind
)
{
	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	typedef
	fcppt::either::object<
		std::string,
		bool
	>
	either_bool;

	auto const bind_function(
		[](
			int const _value
		)
		{
			return
				either_bool(
					_value
					>
					10
				);
		}
	);

	either_bool const result_failure(
		fcppt::either::bind(
			either_int(
				std::string(
					"test"
				)
			),
			bind_function
		)
	);

	BOOST_REQUIRE(
		result_failure.has_failure()
	);

	BOOST_CHECK_EQUAL(
		result_failure.get_failure_unsafe(),
		std::string(
			"test"
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::bind(
			either_int(
				20
			),
			bind_function
		),
		either_bool(
			true
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::bind(
			either_int(
				20
			),
			[](
				int
			)
			{
				return
					either_bool(
						std::string(
							"failure"
						)
					);
			}
		),
		either_bool(
			std::string(
				"failure"
			)
		)
	);
}
