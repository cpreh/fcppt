//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/center.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	box_center
)
{
	typedef fcppt::math::box::object<
		int,
		3
	> box_type;

	box_type const b(
		box_type::vector(10,12,14),
		box_type::dim(24,26,4)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::box::center(
			b
		),
		box_type::vector(22,25,16)
	);
}
