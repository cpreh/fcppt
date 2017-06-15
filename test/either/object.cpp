//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
	either_object
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either;

	either const test1(
		std::string(
			"failure"
		)
	);

	either const test2(
		42
	);

	BOOST_REQUIRE(
		test1.has_failure()
	);

	BOOST_CHECK_EQUAL(
		test1.get_failure_unsafe(),
		std::string(
			"failure"
		)
	);

	BOOST_REQUIRE(
		test2.has_success()
	);

	BOOST_CHECK_EQUAL(
		test2.get_success_unsafe(),
		42
	);
}
