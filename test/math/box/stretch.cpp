//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/componentwise_equal.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/stretch.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(box_stretch)
{
	typedef fcppt::math::box::basic<
		float,
		3
	> box_type;

	box_type b(
		box_type::vector(10,12,14),
		box_type::dim(24,26,4));

	BOOST_CHECK(
		fcppt::math::box::componentwise_equal(
			fcppt::math::box::stretch(
				b,
				2.0f
			),
			box_type(
				box_type::vector(
					-2,
					-1,
					12
				),
				box_type::dim(
					48,
					52,
					8
				)
			),
			std::numeric_limits<
				float
			>::epsilon()
		)
	);
}
