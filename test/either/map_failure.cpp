//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::map_failure",
	"[either]"
)
{
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

	CHECK(
		fcppt::either::map_failure(
			either_char(
				'0'
			),
			map_function
		).has_failure()
	);

	CHECK(
		fcppt::either::map_failure(
			either_char(
				'0'
			),
			map_function
		)
		==
		either_string(
			std::string(
				"0"
			)
		)
	);

	CHECK(
		fcppt::either::map_failure(
			either_char(
				int_strong{
					10
				}
			),
			map_function
		)
		==
		either_string(
			int_strong{
				10
			}
		)
	);
}
