//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/make_range.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"range::size",
	"[range]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec1{
		1,
		2
	};

	CHECK(
		fcppt::range::size(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.begin()
			)
		)
		==
		0u
	);

	CHECK(
		fcppt::range::size(
			fcppt::iterator::make_range(
				vec1.begin(),
				std::next(
					vec1.begin()
				)
			)
		)
		==
		1u
	);

	CHECK(
		fcppt::range::size(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.end()
			)
		)
		==
		2u
	);
}
