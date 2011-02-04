//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector.hpp>
#include <fcppt/container/array.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <sstream>

namespace
{

typedef fcppt::container::raw_vector<
	int
> container_type;

}

template class fcppt::container::raw_vector<
	int
>;

BOOST_AUTO_TEST_CASE(container_raw_vector_shrink)
{
	container_type test;

	test.resize_uninitialized(
		100u
	);

	test.reserve(
		1000u
	);

	BOOST_REQUIRE(
		test.capacity() >= 1000u
	);

	test.shrink_to_fit();

	BOOST_REQUIRE(
		test.capacity() == 100u
	);

	BOOST_REQUIRE(
		test.size() == 100u
	);
}

BOOST_AUTO_TEST_CASE(container_raw_vector_insert)
{
	container_type test;

	test.push_back(10);
	test.push_back(20);

	BOOST_REQUIRE(
		test.size() == 2u
	);

	test.insert(
		test.begin() + 1u,
		30
	);

	BOOST_REQUIRE(
		test.size() == 3u
		&& test[0] == 10
		&& test[1] == 30
		&& test[2] == 20
	);

	test.insert(
		test.begin() + 2,
		2u,
		40
	);

	BOOST_REQUIRE(
		test.size() == 5u
		&& test[0] == 10
		&& test[1] == 30
		&& test[2] == 40
		&& test[3] == 40
		&& test[4] == 20
	);
}

BOOST_AUTO_TEST_CASE(container_raw_vector_insert_iterator)
{
	container_type test;

	typedef fcppt::container::array<
		int,
		5
	> int_array;

	int_array const array = {{
		0, 1, 2, 3, 4
	}};

	test.insert(
		test.begin(),
		array.begin(),
		array.end()
	);

	BOOST_REQUIRE(
		test.size() == 5u
		&& test[0] == 0
		&& test[1] == 1
		&& test[2] == 2
		&& test[3] == 3
		&& test[4] == 4
	);

	std::stringstream stream;

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

	BOOST_REQUIRE(
		stream.eof()
	);

	BOOST_REQUIRE(
		test.size() == 10
		&& test[5] == 10
		&& test[6] == 20
		&& test[7] == 30
		&& test[8] == 40
		&& test[9] == 50
	);
}

BOOST_AUTO_TEST_CASE(container_raw_vector_push_back)
{
	container_type test;

	for(
		container_type::size_type i(0);
		i < 50u;
		++i
	)
		test.push_back(
			static_cast<
				container_type::value_type
			>(i)
		);
	
	for(
		container_type::size_type i(0);
		i < test.size();
		++i
	)
		BOOST_REQUIRE(
			test[i]
			== static_cast<
				container_type::value_type
			>(i)
		);
}

BOOST_AUTO_TEST_CASE(container_raw_vector_erase)
{
	container_type test;

	for(
		container_type::size_type i(0);
		i < 5u;
		++i
	)
		test.push_back(
			static_cast<
				container_type::value_type
			>(i)
		);
	
	test.erase(
		test.begin() + 3
	);

	BOOST_REQUIRE(
		test.size() == 4u
		&& test[0] == 0
		&& test[1] == 1
		&& test[2] == 2
		&& test[3] == 4
	);

	test.erase(
		test.begin() + 1,
		test.begin() + 3
	);

	BOOST_REQUIRE(
		test.size() == 2u
		&& test[0] == 0
		&& test[1] == 4
	);

	test.clear();

	BOOST_REQUIRE(
		test.empty()
	);
}

BOOST_AUTO_TEST_CASE(container_raw_vector_copy)
{
	container_type test;

	for(
		container_type::size_type i(0);
		i < 1000u;
		++i
	)
		test.push_back(
			static_cast<
				container_type::value_type
			>(i)
		);
	
	container_type test2(test);

	BOOST_REQUIRE(
		test == test2
	);

	container_type test3;

	test3 = test;

	BOOST_REQUIRE(
		test == test3
	);
}

BOOST_AUTO_TEST_CASE(container_raw_vector_empy_copy)
{
	container_type test;

	container_type test2(test);

	BOOST_REQUIRE(
		test2.empty()
	);
}
