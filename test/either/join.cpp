//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/join.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::join",
	"[either]"
)
{
	typedef
	fcppt::either::object<
		int,
		std::string
	>
	inner_either;

	typedef
	fcppt::either::object<
		int,
		inner_either
	>
	outer_either;

	CHECK(
		fcppt::either::join(
			outer_either(
				5
			)
		)
		==
		inner_either(
			5
		)
	);

	CHECK(
		fcppt::either::join(
			outer_either(
				inner_either(
					5
				)
			)
		)
		==
		inner_either(
			5
		)
	);

	CHECK(
		fcppt::either::join(
			outer_either(
				inner_either(
					std::string(
						"test"
					)
				)
			)
		)
		==
		inner_either(
			std::string(
				"test"
			)
		)
	);
}
