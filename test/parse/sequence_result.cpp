//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/parse/detail/sequence_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::detail::sequence_result",
	"[parse]"
)
{
	CHECK(
		fcppt::parse::detail::sequence_result(
			fcppt::unit{},
			fcppt::unit{}
		)
		==
		fcppt::unit{}
	);

	CHECK(
		fcppt::parse::detail::sequence_result(
			fcppt::unit{},
			42
		)
		==
		42
	);

	CHECK(
		fcppt::parse::detail::sequence_result(
			42,
			fcppt::unit{}
		)
		==
		42
	);

	CHECK(
		fcppt::parse::detail::sequence_result(
			42,
			false
		)
		==
		std::make_tuple(
			42,
			false
		)
	);

	CHECK(
		fcppt::parse::detail::sequence_result(
			42,
			std::make_tuple(
				'X',
				false
			)
		)
		==
		std::make_tuple(
			42,
			'X',
			false
		)
	);

	CHECK(
		fcppt::parse::detail::sequence_result(
			std::make_tuple(
				'Y',
				true
			),
			std::make_tuple(
				'X',
				false
			)
		)
		==
		std::make_tuple(
			'Y',
			true,
			'X',
			false
		)
	);

	CHECK(
		fcppt::parse::detail::sequence_result(
			'Y',
			fcppt::parse::detail::sequence_result(
				fcppt::unit{},
				42
			)
		)
		==
		std::make_tuple(
			'Y',
			42
		)
	);
}
