//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_TO_ANGLE_AND_AXIS_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_TO_ANGLE_AND_AXIS_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/math/quaternion.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace quaternion
{
/// Converts a quaternion to an angle and and axis
template<typename T>
void
to_angle_and_axis(
	boost::math::quaternion<T> const &q,
	T &angle,
	typename fcppt::math::vector::static_<T,3>::type &axis)
{
	// NOTE: Can we express this with quaternion functions instead of the manual sqrt?
	T const scale =
		std::sqrt(
			q.R_component_2() * q.R_component_2() +
			q.R_component_3() * q.R_component_3() +
			q.R_component_4() * q.R_component_4());

	axis.x() = q.R_component_2() / scale;
	axis.y() = q.R_component_3() / scale;
	axis.z() = q.R_component_4() / scale;
	angle = std::acos(q.R_component_1()) * static_cast<T>(2.0);
}
}
}
}

#endif
