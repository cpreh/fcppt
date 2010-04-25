#ifndef FCPPT_MATH_QUATERNION_TO_MATRIX_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_TO_MATRIX_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/transpose.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <boost/math/quaternion.hpp>

namespace fcppt
{
namespace math
{
namespace quaternion
{
/// Converts a quaternion to a rotation matrix
template
<
	typename T
>
typename fcppt::math::matrix::static_<T,4,4>::type const
to_matrix(
	boost::math::quaternion<T> const &q)
{
	T const &
		s = q.R_component_1(),
		x = q.R_component_2(),
		y = q.R_component_3(),
		z = q.R_component_4();
		
	return 
		// NOTE: more ugly static_casts here?
		// NOTE: Maybe transpose this?
		typename fcppt::math::matrix::static_<T,4,4>::type(
			1-2*(y*y + z*z), 2*x*y-2*s*z, 2*s*y + 2*x*z, 0,
			2*x*y+2*s*z, 1-2*(x*x + z*z),-2*s*x+2*y*z,0,
			-2*s*y + 2*x*z,2*s*x+2*y*z,1-2*(x*x+y*y),0,
			0,0,0,1);
}
}
}
}

#endif
