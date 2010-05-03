//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/quaternion/from_angle_and_axis.hpp>
#include <fcppt/math/quaternion/vector_rotation.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/pi.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(from_angle_and_axis)
{
	typedef float element_type;

	typedef boost::math::quaternion<
		element_type
	> quaternion;

	typedef fcppt::math::vector::static_<
		element_type,
		3
	>::type vector_type;

	quaternion const rot(
		fcppt::math::quaternion::from_angle_and_axis(
			fcppt::math::pi<
				element_type
			>(),
			vector_type(
				0,
				1,
				0
			)
		)
	);

	BOOST_REQUIRE(
		fcppt::math::quaternion::vector_rotation(
			vector_type(
				1,
				0,
				0
			),
			rot
		)
		== vector_type(
			-1,
			0,
			0
		)
	);
}
