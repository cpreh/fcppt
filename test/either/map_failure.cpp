//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/map_failure.hpp>
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
	either_map_failure
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_string;

	typedef
	fcppt::either::object<
		char,
		int
	>
	either_char;

	auto const map_function(
		[](
			char const _value
		)
		{
			return
				std::string{
					1u,
					_value
				};
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::map_failure(
			either_char(
				'0'
			),
			map_function
		),
		either_string(
			std::string(
				"0"
			)
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::map_failure(
			either_char(
				10
			),
			map_function
		),
		either_string(
			10
		)
	);
}
