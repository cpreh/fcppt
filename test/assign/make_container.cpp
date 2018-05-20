//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"assign::make_container",
	"[assign]"
)
{
	typedef
	std::vector<
		fcppt::unique_ptr<
			int
		>
	>
	sequence;

	sequence const result(
		fcppt::assign::make_container<
			sequence
		>(
			fcppt::make_unique_ptr<
				int
			>(
				3
			),
			fcppt::make_unique_ptr<
				int
			>(
				4
			),
			fcppt::make_unique_ptr<
				int
			>(
				5
			)

		)
	);

	REQUIRE(
		result.size()
		==
		3u
	);

	CHECK(
		*result[0]
		==
		3
	);

	CHECK(
		*result[1]
		==
		4
	);

	CHECK(
		*result[2]
		==
		5
	);
}
