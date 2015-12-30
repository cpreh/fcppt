//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/map.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_map
)
{
FCPPT_PP_POP_WARNING

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

	auto const map_function(
		[](
			int const _value
		)
		{
			return
				_value
				>
				10;
		}
	);

	either_bool const result_failure(
		fcppt::either::map(
			either_int(
				std::string(
					"test"
				)
			),
			map_function
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

	either_bool const result_success(
		fcppt::either::map(
			either_int(
				20
			),
			map_function
		)
	);

	BOOST_REQUIRE(
		result_success.has_success()
	);

	BOOST_CHECK_EQUAL(
		result_success.get_success_unsafe(),
		true
	);
}
