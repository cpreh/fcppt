//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::construct",
	"[either]"
)
{
	CHECK(
		fcppt::either::construct(
			true,
			fcppt::const_(
				42
			),
			fcppt::const_(
				'x'
			)
		)
		==
		fcppt::either::object<
			char,
			int
		>{
			42
		}
	);

	CHECK(
		fcppt::either::construct(
			false,
			fcppt::const_(
				42
			),
			fcppt::const_(
				'x'
			)
		)
		==
		fcppt::either::object<
			char,
			int
		>{
			'x'
		}
	);
}
