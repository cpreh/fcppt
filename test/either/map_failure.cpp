//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
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

	FCPPT_MAKE_STRONG_TYPEDEF(
		int,
		int_strong
	);

	typedef
	fcppt::either::object<
		std::string,
		int_strong
	>
	either_string;

	typedef
	fcppt::either::object<
		char,
		int_strong
	>
	either_char;

	auto const map_function(
		[](
			char const _value
		)
		{
			return
				std::string{
					_value
				};
		}
	);

	BOOST_CHECK(
		fcppt::either::map_failure(
			either_char(
				'0'
			),
			map_function
		).has_failure()
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
				int_strong{
					10
				}
			),
			map_function
		),
		either_string(
			int_strong{
				10
			}
		)
	);
}
