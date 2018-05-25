//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector/comparison.hpp>
#include <fcppt/container/raw_vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <catch.hpp>
#include <iterator>
#include <sstream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::container::raw_vector::object<
	int
>
int_vector;

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
		100u,
		0
	);

	test.reserve(
		1000u
	);

	CHECK(
		test.capacity()
		>=
		1000u
	);

	test.shrink_to_fit();

	CHECK(
		test.capacity()
		==
		100u
	);

	CHECK(
		test.size()
		==
		100u
	);
}

TEST_CASE(
	"container::raw_vector shrink"
	"[container],[raw_vector]"
)
{
	int_vector test(
		10u,
		0
	);

	CHECK(
		test.size()
		==
		10u
	);

	test.resize(
		5u,
		0
	);

	CHECK(
		test.size()
		==
		5u
	);
}

TEST_CASE(
	"container::raw_vector::insert",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	test.push_back(
		10
	);

	test.push_back(
		20
	);

	REQUIRE(
		test.size()
		==
		2u
	);

	test.insert(
		test.begin() + 1u,
		30
	);

	REQUIRE(
		test
		==
		int_vector{
			10,
			30,
			20
		}
	);

	test.insert(
		test.begin() + 2,
		2u,
		40
	);

	CHECK(
		test
		==
		int_vector{
			10,
			30,
			40,
			40,
			20
		}
	);
}

TEST_CASE(
	"container::raw_vector insert iterator",
	"[container],[raw_vector]"
)
{
	int_vector test{};

	typedef
	std::array<
		int,
		5
	>
	int_array;

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

	std::stringstream stream{};

	stream
		<< 10 << ' '
		<< 20 << ' '
		<< 30 << ' '
		<< 40 << ' '
		<< 50;

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
			10,
			20,
			30,
			40,
			50
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
		i < 50;
		++i
	)
		test.push_back(
			i
		);

	for(
		int_vector::size_type i{
			0
		};
		i < test.size();
		++i
	)
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
		i < 5;
		++i
	)
		test.push_back(
			i
		);

	REQUIRE(
		test.size()
		==
		5u
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
		100u,
		0
	);

	test1[0] = 500;

	int_vector test2(
		std::move(
			test1
		)
	);

	REQUIRE(
		test2.size()
		==
		100u
	);

	CHECK(
		test2[0]
		==
		500
	);

	CHECK(
		test1.empty()
	);

	int_vector test3{};

	test3 =
		std::move(
			test2
		);

	REQUIRE(
		test3.size()
		==
		100u
	);

	CHECK(
		test3[0]
		==
		500
	);

	CHECK(
		test2.empty()
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
		3u
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
