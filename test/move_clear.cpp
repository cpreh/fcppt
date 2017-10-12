//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/move_clear.hpp>
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
	move_clear
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector ints{
		1,2
	};

	int_vector moved(
		fcppt::move_clear(
			ints
		)
	);

	BOOST_REQUIRE_EQUAL(
		moved.size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		moved[0],
		1
	);

	BOOST_CHECK_EQUAL(
		moved[1],
		2
	);

	BOOST_CHECK(
		ints.empty()
	);
}
