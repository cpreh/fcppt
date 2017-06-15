//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/set_intersection.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>



FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_set_intersection
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::set<
		int
	>
	int_set;

	BOOST_CHECK((
		fcppt::algorithm::set_intersection(
			int_set{
				1, 2, 3
			},
			int_set{
				2, 3, 4
			}
		)
		==
		int_set{
			2, 3
		}
	));
}
