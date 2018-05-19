//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::failure_opt",
	"[either]"
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

	CHECK(
		fcppt::either::failure_opt(
			either_int(
				std::string(
					"test"
				)
			)
		)
		==
		optional_string(
			std::string(
				"test"
			)
		)
	);

	CHECK(
		fcppt::either::failure_opt(
			either_int(
				42
			)
		)
		==
		optional_string()
	);
}
