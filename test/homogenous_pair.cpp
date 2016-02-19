//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/homogenous_pair.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	homogenous_pair
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::homogenous_pair<
		int
	> int_homogenous_pair;

	BOOST_CHECK(
		int_homogenous_pair(
			5,
			6
		)
		<
		int_homogenous_pair(
			5,
			7
		)
	);

	BOOST_CHECK(
		int_homogenous_pair(
			3,
			6
		)
		<
		int_homogenous_pair(
			5,
			1
		)
	);

	BOOST_CHECK(
		int_homogenous_pair(
			3,
			6
		)
		!=
		int_homogenous_pair(
			5,
			1
		)
	);

	BOOST_CHECK(
		int_homogenous_pair(
			2,
			3
		)
		==
		int_homogenous_pair(
			2,
			3
		)
	);
}
