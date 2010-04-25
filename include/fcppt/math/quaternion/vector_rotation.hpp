#ifndef FCPPT_MATH_QUATERNION_VECTOR_ROTATION_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_VECTOR_ROTATION_HPP_INCLUDED

#include <fcppt/math/vector/static.hpp>
#include <boost/math/quaternion.hpp>

namespace fcppt
{
namespace math
{
namespace quaternion
{
/// Rotates a vector using a quaternion
template<typename T>
typename fcppt::math::vector::static_<T,3>::type const
vector_rotation(
	typename fcppt::math::vector::static_<T,3>::type const &v,
	boost::math::quaternion<T> const &q)
{
	typedef typename 
	fcppt::math::vector::static_<T,3>::type
	vector;

	typedef 
	boost::math::quaternion<T> 
	quaternion;
	
	quaternion const p(
		static_cast<T>(
			0),
		v[0],
		v[1],
		v[2]);
	
	quaternion const result = 
		q * 
		p * 
		boost::math::conj(
			q);
	
	return 
		vector(
			result.R_component_1(),
			result.R_component_2(),
			result.R_component_3());
}
}
}
}

#endif
