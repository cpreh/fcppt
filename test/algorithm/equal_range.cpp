//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/equal_range.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/iterator/range_comparison.hpp>
#include <fcppt/range/empty.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm equal_range"
	"[algorithm_equal_range]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		2,
		5,
		7
	};

	CHECK(
		fcppt::range::empty(
			fcppt::algorithm::equal_range(
				vec,
				3
			)
		)
	);

	CHECK(
		fcppt::algorithm::equal_range(
			vec,
			5
		)
		==
		fcppt::iterator::make_range(
			std::next(
				vec.begin(),
				1
			),
			std::next(
				vec.begin(),
				2
			)
		)
	);
}
