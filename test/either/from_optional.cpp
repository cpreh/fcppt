//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::from_optional",
	"[either]"
)
{
	typedef
	fcppt::optional::object<
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

	CHECK(
		fcppt::either::from_optional(
			optional_int(
				42
			),
			failure_function
		)
		==
		either_int(
			42
		)
	);

	CHECK(
		fcppt::either::from_optional(
			optional_int(),
			failure_function
		)
		==
		either_int(
			std::string(
				"failure"
			)
		)
	);
}
