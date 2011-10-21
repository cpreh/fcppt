//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/compare.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/math/quaternion/from_angle_and_axis.hpp>
#include <fcppt/math/quaternion/to_angle_and_axis.hpp>
#include <fcppt/math/quaternion/vector_rotation.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(all_quaternion)
{
	typedef float element_type;

	typedef boost::math::quaternion<
		element_type
	> quaternion;

	typedef fcppt::math::vector::static_<
		element_type,
		3
	>::type vector_type;

	element_type const original_angle =
		fcppt::math::pi<element_type>();
	vector_type const original_axis =
		vector_type(
				0,
				1,
				0);

	quaternion const rot(
		fcppt::math::quaternion::from_angle_and_axis(
			original_angle,
			original_axis));

	element_type angle;
	vector_type axis;

	fcppt::math::quaternion::to_angle_and_axis(
		rot,
		angle,
		axis);

	BOOST_CHECK(
		fcppt::math::compare(
			angle,
			original_angle) &&
		axis == original_axis);

	BOOST_CHECK(
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
