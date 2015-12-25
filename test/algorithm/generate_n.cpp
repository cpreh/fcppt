//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/generate_n.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_generate_n
)
{
FCPPT_PP_POP_WARNING


	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const result(
		fcppt::algorithm::generate_n<
			int_vector
		>(
			3,
			[]{
				static int index{
					0
				};

				return
					index++;
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		3u
	);

	BOOST_CHECK_EQUAL(
		result[0],
		0
	);

	BOOST_CHECK_EQUAL(
		result[1],
		1
	);

	BOOST_CHECK_EQUAL(
		result[2],
		2
	);
}
