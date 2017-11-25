//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/istringstream.hpp>
#include <fcppt/math/vector/input.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	vector_input
)
{
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
