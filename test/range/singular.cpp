//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/make_range.hpp>
#include <fcppt/range/singular.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"range::singular",
	"[range]"
)
{
	using
	int_vector
	=
	std::vector<
		int
	>;

	int_vector const vec1{
		1,
		2
	};

	CHECK_FALSE(
		fcppt::range::singular(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.begin()
			)
		)
	);

	CHECK(
		fcppt::range::singular(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.begin() + 1
			)
		)
	);

	CHECK_FALSE(
		fcppt::range::singular(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.end()
			)
		)
	);
}
