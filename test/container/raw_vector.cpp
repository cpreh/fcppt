//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <iterator>
#include <sstream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef fcppt::container::raw_vector<
	int
> container_type;

}

template class fcppt::container::raw_vector<
	int
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_shrink_to_fit
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_shrink
)
{
FCPPT_PP_POP_WARNING

	container_type test;

	test.assign(
		10u,
		42
	);

	BOOST_REQUIRE(
		test.size() == 10u
	);

	test.resize_uninitialized(
		5u
	);

	BOOST_REQUIRE(
		test.size() == 5u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_insert
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_insert_iterator
)
{
FCPPT_PP_POP_WARNING

	container_type test;

	typedef std::array<
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_push_back
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_erase
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_copy
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_empty_copy
)
{
FCPPT_PP_POP_WARNING

	container_type test;

	container_type test2(test);

	BOOST_REQUIRE(
		test2.empty()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_move
)
{
FCPPT_PP_POP_WARNING

	container_type test1(
		100
	);

	test1[0] = 500;

	container_type test2(
		std::move(
			test1
		)
	);

	BOOST_CHECK(
		test2.size()
		==
		100
		&&
		test2[0]
		==
		500
	);

	BOOST_CHECK(
		test1.empty()
	);

	container_type test3;

	test3 =
		std::move(
			test2
		);

	BOOST_CHECK(
		test3.size()
		==
		100
		&&
		test3[0]
		==
		500
	);

	BOOST_CHECK(
		test2.empty()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_raw_vector_initializer_list
)
{
FCPPT_PP_POP_WARNING

	container_type const test1{
		1,
		2,
		3
	};

	BOOST_REQUIRE(
		test1.size() == 3u
	);

	BOOST_CHECK(
		test1[0] == 1
		&&
		test1[1] == 2
		&&
		test1[2] == 3
	);
}
