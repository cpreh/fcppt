//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/contains_set.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_contains_set
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::unordered_set<
		int
	>
	int_set;

	int_set ints;

	ints.insert(
		42
	);

	BOOST_CHECK(
		fcppt::algorithm::contains_set(
			ints,
			42
		)
	);

	BOOST_CHECK(
		!fcppt::algorithm::contains_set(
			ints,
			100
		)
	);
}
