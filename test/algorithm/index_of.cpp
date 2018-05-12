//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/index_of.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
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
		fcppt::algorithm::index_of(
			vec,
			2
		)
		==
		fcppt::optional::make(
			int_vector::size_type{
				1u
			}
		)
	);

	CHECK(
		fcppt::algorithm::index_of(
			vec,
			3
		)
		==
		fcppt::optional::make(
			int_vector::size_type{
				2u
			}
		)
	);

	CHECK(
		!fcppt::algorithm::index_of(
			vec,
			4
		).has_value()
	);
}
