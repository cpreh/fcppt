//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/fill.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	vector_fill
)
{
	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	ui2_vector const vector(
		fcppt::math::vector::fill<
			ui2_vector
		>(
			42u
		)
	);

	BOOST_CHECK_EQUAL(
		vector.x(),
		42u
	);

	BOOST_CHECK_EQUAL(
		vector.y(),
		42u
	);
}
