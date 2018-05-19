//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/error_from_optional.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::error_from_optional",
	"[either]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	fcppt::either::error<
		int
	>
	either_int;

	CHECK(
		fcppt::either::error_from_optional(
			optional_int{
				42
			}
		)
		==
		either_int{
			42
		}
	);

	CHECK(
		fcppt::either::error_from_optional(
			optional_int()
		)
		==
		either_int{
			fcppt::either::no_error{}
		}
	);
}
