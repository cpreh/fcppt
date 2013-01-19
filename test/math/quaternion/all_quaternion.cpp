//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/pi.hpp>
#include <fcppt/math/range_compare.hpp>
#include <fcppt/math/quaternion/from_angle_and_axis.hpp>
#include <fcppt/math/quaternion/to_angle_and_axis.hpp>
#include <fcppt/math/quaternion/vector_rotation.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(all_quaternion)
{
FCPPT_PP_POP_WARNING

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

	element_type const epsilon = 0.001f;

	BOOST_CHECK(
		std::abs(angle - original_angle) < epsilon
	);

	BOOST_CHECK(
		fcppt::math::vector::componentwise_equal(
			axis,
			original_axis,
			epsilon
		)
	);

	BOOST_CHECK((
		fcppt::math::range_compare(
			fcppt::math::quaternion::vector_rotation(
				vector_type(
					1,
					0,
					0),
				rot),
		vector_type(
			-1,
			0,
			0),
		epsilon)));
}
