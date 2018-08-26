//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::to_exception",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	auto const make_exception(
		[]{
			return
				fcppt::exception(
					FCPPT_TEXT("Invalid")
				);
		}
	);

	CHECK(
		fcppt::optional::to_exception(
			optional_int(
				3
			),
			make_exception
		)
		==
		3
	);

	CHECK_THROWS_AS(
		fcppt::optional::to_exception(
			optional_int(),
			make_exception
		),
		fcppt::exception
	);
}
