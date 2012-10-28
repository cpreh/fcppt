//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/join.hpp>
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
	algorithm_join_vector
)
{
FCPPT_PP_POP_WARNING

	typedef std::vector<
		int
	> int_vector;

	int_vector vec1;

	vec1.push_back(1);
	vec1.push_back(2);

	int_vector vec2;

	vec2.push_back(3);
	vec2.push_back(4);

	int_vector const result(
		fcppt::algorithm::join(
			vec1,
			vec2
		)
	);

	BOOST_REQUIRE(
		result.size() == 4u
		&& result[0] == 1
		&& result[1] == 2
		&& result[2] == 3
		&& result[3] == 4
	);
}
