//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
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
	either_from_optional
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	auto const failure_function(
		[]{
			return
				std::string(
					"failure"
				);
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::from_optional(
			optional_int(
				42
			),
			failure_function
		),
		either_int(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::from_optional(
			optional_int(),
			failure_function
		),
		either_int(
			std::string(
				"failure"
			)
		)
	);
}
