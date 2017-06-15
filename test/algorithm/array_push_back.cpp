//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/array_push_back.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	array_push_back
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::array<
		int,
		3
	> int3_array;

	typedef
	std::array<
		int,
		4
	> int4_array;

	int3_array const test{{
		1,
		2,
		3
	}};

	int4_array const result(
		fcppt::algorithm::array_push_back(
			test,
			4
		)
	);

	BOOST_CHECK_EQUAL(
		result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		result[1],
		2
	);

	BOOST_CHECK_EQUAL(
		result[2],
		3
	);

	BOOST_CHECK_EQUAL(
		result[3],
		4
	);
}
