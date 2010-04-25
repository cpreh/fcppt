#ifndef FCPPT_MATH_QUATERNION_IS_NORMALIZED_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_IS_NORMALIZED_HPP_INCLUDED

#include <fcppt/math/compare.hpp>
#include <fcppt/math/quaternion/dot.hpp>
#include <boost/math/quaternion.hpp>

namespace fcppt
{
namespace math
{
namespace quaternion
{
/// Tests if the quaternion has norm 1
template<typename T>
bool
is_normalized(
	boost::math::quaternion<T> const &r)
{
	return 
		fcppt::math::compare(
			dot(
				r,
				r),
			static_cast<T>(1));
}
}
}
}

#endif
