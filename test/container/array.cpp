//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/array.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <string>
#include <fcppt/config/external_end.hpp>

template struct fcppt::container::array<
	int,
	5
>;

template struct fcppt::container::array<
	int,
	0
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_array_fundamental
)
{
FCPPT_PP_POP_WARNING

	fcppt::container::array<
		int,
		10
	> array;

	BOOST_REQUIRE(
		array.size() == 10
	);

	array.fill(42);

	BOOST_REQUIRE(
		std::count(
			array.begin(),
			array.end(),
			42
		)
		== 10
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	array_string
)
{
FCPPT_PP_POP_WARNING

	fcppt::container::array<
		std::string,
		3
	> array;

	BOOST_REQUIRE(
		array.size() == 3
	);

	array[0] = "foo";
	array[1] = "bar";
	array[2] = "baz";

	BOOST_REQUIRE(
		array[0] == "foo"
		&& array[1] == "bar"
		&& array[2] == "baz"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	array_empty
)
{
FCPPT_PP_POP_WARNING

	fcppt::container::array<
		int,
		0
	> array;

	BOOST_REQUIRE(
		array.empty()
	);

	BOOST_REQUIRE(
		array.begin()
		== array.end()
	);

	BOOST_REQUIRE(
		array.data()
		== array.data_end()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	array_compare
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::container::array<
		int,
		3
	> int3_array;

	int3_array const array1 =
	{{
		1, 2, 3
	}};

	int3_array const array2 =
	{{
		1, 2, 3
	}};

	int3_array const array3 =
	{{
		2, 3, 4
	}};

	BOOST_CHECK(
		array1 == array2
	);

	BOOST_CHECK(
		array1 != array3
	);

	BOOST_CHECK(
		array1 < array3
	);

	BOOST_CHECK(
		array3 > array1
	);

	BOOST_CHECK(
		array1 <= array2
	);

	BOOST_CHECK(
		array1 >= array2
	);
}
