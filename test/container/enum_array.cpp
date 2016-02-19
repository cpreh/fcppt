//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/enum_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class my_enum
{
	val1,
	val2,
	val3,
	fcppt_maximum = val3
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_data
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::enum_array<
		my_enum,
		int
	>
	int_array;

	int_array const test1{{{
		1,
		2,
		3
	}}};

	BOOST_CHECK_EQUAL(
		test1[
			my_enum::val1
		],
		1
	);

	int_array const test2{{{
		1,
		2,
		3
	}}};

	BOOST_CHECK(
		test1
		==
		test2
	);

	int_array const test3{{{
		1,
		2,
		4
	}}};

	BOOST_CHECK(
		test1
		!=
		test3
	);
}
