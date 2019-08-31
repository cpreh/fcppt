//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/range_impl.hpp>
#include <fcppt/range/from_pair.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"range::from_pair",
	"[range]"
)
{
	fcppt::iterator::range<
		int
	> const range{
		fcppt::range::from_pair(
			std::make_pair(
				3,
				5
			)
		)
	};

	CHECK(
		range.begin()
		==
		3
	);

	CHECK(
		range.end()
		==
		5
	);
}
