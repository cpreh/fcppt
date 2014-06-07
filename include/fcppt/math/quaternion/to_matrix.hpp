//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_TO_MATRIX_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_TO_MATRIX_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/transpose.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/math/quaternion.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace quaternion
{
/**
\brief Converts a quaternion to a static 4x4 rotation matrix
\ingroup fcpptmathquaternion
\tparam T The quaternion's value type (has to be a floating point type)
*/
template
<
	typename T
>
fcppt::math::matrix::static_<T,4,4> const
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
		fcppt::math::matrix::static_<T,4,4>(
			1-2*(y*y + z*z), 2*x*y-2*s*z, 2*s*y + 2*x*z, 0,
			2*x*y+2*s*z, 1-2*(x*x + z*z),-2*s*x+2*y*z,0,
			-2*s*y + 2*x*z,2*s*x+2*y*z,1-2*(x*x+y*y),0,
			0,0,0,1);
}
}
}
}

#endif
