#ifndef FCPPT_MATH_QUATERNION_NORMALIZE_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_NORMALIZE_HPP_INCLUDED

#include <fcppt/math/quaternion/dot.hpp>
#include <boost/math/quaternion.hpp>

namespace fcppt
{
namespace math
{
namespace quaternion
{
template<typename T>
boost::math::quaternion<T> const
normalize(
	boost::math::quaternion<T> const &q)
{
	T const norm = 
		dot(q,q);
	return
		q / norm;
}
}
}
}

#endif
