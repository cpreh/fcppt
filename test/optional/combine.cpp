//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/combine.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::combine",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	std::plus<
		int
	> const add{};

	CHECK(
		fcppt::optional::combine(
			optional_int(
				10
			),
			optional_int(
				20
			),
			add
		)
		==
		optional_int(
			30
		)
	);

	CHECK(
		fcppt::optional::combine(
			optional_int(
				10
			),
			optional_int(),
			add
		)
		==
		optional_int(
			10
		)
	);

	CHECK(
		fcppt::optional::combine(
			optional_int(),
			optional_int(
				20
			),
			add
		)
		==
		optional_int(
			20
		)
	);

	CHECK(
		fcppt::optional::combine(
			optional_int(),
			optional_int(),
			add
		)
		==
		optional_int()
	);
}
