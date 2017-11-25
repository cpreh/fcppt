//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum/array.hpp>
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

BOOST_AUTO_TEST_CASE(
	enum_array
)
{
	typedef
	fcppt::enum_::array<
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
