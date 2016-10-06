//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/make_failure.hpp>
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
	either_make_failure
)
{
FCPPT_PP_POP_WARNING

	fcppt::either::object<
		std::string,
		int
	> const result{
		fcppt::either::make_failure<
			int
		>(
			std::string{
				"test"
			}
		)
	};

	BOOST_CHECK(
		!result.has_success()
	);
}
