//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/istringstream.hpp>
#include <fcppt/math/vector/input.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_input
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	{
		fcppt::io::istringstream stream(
			FCPPT_TEXT("(42, 3)")
		);

		ui2_vector result(
			fcppt::no_init{}
		);

		BOOST_CHECK(
			stream
				>> result
		);

		BOOST_CHECK_EQUAL(
			result.x(),
			42u
		);

		BOOST_CHECK_EQUAL(
			result.y(),
			3u
		);
	}

	{
		fcppt::io::istringstream stream(
			FCPPT_TEXT("(42, 3")
		);

		ui2_vector result(
			fcppt::no_init{}
		);

		BOOST_CHECK(
			!(
				stream
					>> result
			)
		);
	}
}
