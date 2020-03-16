//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector/comparison.hpp>
#include <fcppt/container/raw_vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <iterator>
#include <sstream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

using
int_vector
=
fcppt::container::raw_vector::object<
	int
>;

}

template
class
fcppt::container::raw_vector::object<
	int
>;

TEST_CASE(
	"container::raw_vector::shrink_to_fit",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	test.resize(
		100U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		0
	);

	test.reserve(
		1000U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test.capacity()
		>=
		1000U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	test.shrink_to_fit();

	CHECK(
		test.capacity()
		==
		100U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test.size()
		==
		100U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

TEST_CASE(
	"container::raw_vector shrink"
	"[container],[raw_vector]"
)
{
	int_vector test(
		10U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		0
	);

	CHECK(
		test.size()
		==
		10U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	test.resize(
		5U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		0
	);

	CHECK(
		test.size()
		==
		5U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

TEST_CASE(
	"container::raw_vector::insert",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	test.push_back(
		10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	test.push_back(
		20 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	REQUIRE(
		test.size()
		==
		2U
	);

	test.insert(
		test.begin() + 1U,
		30 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	REQUIRE(
		test
		==
		int_vector{
			10, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			30, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			20 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		}
	);

	test.insert(
		test.begin() + 2,
		2U,
		40 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test
		==
		int_vector{
			10, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			30, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			40, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			40, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			20 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		}
	);
}

TEST_CASE(
	"container::raw_vector insert iterator",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	using
	int_array
	=
	std::array<
		int,
		5 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	>;

	int_array const array{{
		0, 1, 2, 3, 4
	}};

	test.insert(
		test.begin(),
		array.begin(),
		array.end()
	);

	CHECK(
		test
		==
		int_vector{
			0,
			1,
			2,
			3,
			4
		}
	);

	std::stringstream stream{}; // NOLINT(fuchsia-default-arguments-calls)

	stream
		<< 10 << ' ' // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		<< 20 << ' ' // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		<< 30 << ' ' // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		<< 40 << ' ' // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		<< 50; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	test.insert(
		test.end(),
		std::istream_iterator<
			int
		>(
			stream
		),
		std::istream_iterator<
			int
		>()
	);

	CHECK(
		stream.eof()
	);

	CHECK(
		test
		==
		int_vector{
			0,
			1,
			2,
			3,
			4,
			10, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			20, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			30, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			40, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			50 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		}
	);
}

TEST_CASE(
	"container::raw_vector::push_back",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	for(
		int_vector::value_type i{
			0
		};
		i < 50; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		++i
	)
	{
		test.push_back(
			i
		);
	}

	for(
		int_vector::size_type i{
			0
		};
		i < test.size();
		++i
	)
	{
		CHECK(
			test[
				i
			]
			==
			static_cast<
				int_vector::value_type
			>(
				i
			)
		);
	}
}

TEST_CASE(
	"container::raw_vector::erase",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	for(
		int_vector::value_type i{
			0
		};
		i < 5; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		++i
	)
	{
		test.push_back(
			i
		);
	}

	REQUIRE(
		test.size()
		==
		5U
	);

	test.erase(
		test.begin()
		+
		3
	);

	CHECK(
		test
		==
		int_vector{
			0,
			1,
			2,
			4
		}
	);

	test.erase(
		test.begin() + 1,
		test.begin() + 3
	);

	CHECK(
		test
		==
		int_vector{
			0,
			4
		}
	);

	test.clear();

	CHECK(
		test.empty()
	);
}

TEST_CASE(
	"container::raw_vector move",
	"[container],[raw_vector]"
)
{
	int_vector test1(
		100U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		0
	);

	test1[0] = 500; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	int_vector test2(
		std::move(
			test1
		)
	);

	REQUIRE(
		test2.size()
		==
		100U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test2[0]
		==
		500 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	int_vector test3{};

	test3 =
		std::move(
			test2
		);

	REQUIRE(
		test3.size()
		==
		100U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test3[0]
		==
		500 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

TEST_CASE(
	"container::raw_vector initializer_list",
	"[container],[raw_vector]"
)
{
	int_vector const test1{
		1,
		2,
		3
	};

	REQUIRE(
		test1.size()
		==
		3U
	);

	CHECK(
		test1[0]
		==
		1
	);

	CHECK(
		test1[1]
		==
		2
	);

	CHECK(
		test1[2]
		==
		3
	);
}
