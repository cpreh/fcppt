//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/make_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Iterator
>
void
test_iterator(
	fcppt::iterator::range<
		Iterator
	> const _range
)
{
	CHECK(
		std::distance(
			_range.begin(),
			_range.end()
		)
		==
		3
	);

	CHECK(
		*_range.begin()
		==
		1
	);

	CHECK(
		*(_range.begin() + 1)
		==
		2
	);

	CHECK(
		*(_range.begin() + 2)
		==
		3
	);
}

}

TEST_CASE(
	"iterator::make_range",
	"[iterator]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector vec1{
		1,
		2,
		3
	};

	int_vector const vec2{
		1,
		2,
		3
	};

	test_iterator(
		fcppt::iterator::make_range(
			vec1.begin(),
			vec1.end()
		)
	);

	test_iterator(
		fcppt::iterator::make_range(
			vec2.begin(),
			vec2.end()
		)
	);
}
