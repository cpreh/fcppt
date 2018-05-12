//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_opt.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/test/defer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm find_opt"
	"[algorithm_find_opt]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		1,
		2,
		3
	};

	CHECK(
		fcppt::test::defer(
			fcppt::algorithm::find_opt(
				vec,
				2
			)
			==
			fcppt::optional::make(
				std::next(
					vec.begin(),
					1
				)
			)
		)
	);

	CHECK(
		!fcppt::algorithm::find_opt(
			vec,
			4
		).has_value()
	);
}
