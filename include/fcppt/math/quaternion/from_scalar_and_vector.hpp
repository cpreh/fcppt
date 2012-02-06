//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_FROM_SCALAR_AND_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_FROM_SCALAR_AND_VECTOR_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
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
\brief Initializes a quaternion from a scalar and a vector.
\ingroup fcpptmathquaternion
\tparam T The quaternion's value type
\tparam N The vector's dimension type (dynamic vectors are allowed)
\tparam S The vector's storage type (dynamic vectors are allowed)
\see fcppt::math::quaternion::from_angle_and_axis.
\note
The vector is <em>not</em> an axis, see fcppt::math::quaternion::from_angle_and_axis for that!
*/
template<typename T>
boost::math::quaternion<T> const
from_scalar_and_vector(
	T const &s,
	fcppt::math::vector::basic<T,N,S> const &v)
{
	return
		boost::math::quaternion<T>(
			s,
			v[0],
			v[1],
			v[2]);
}
}
}
}

#endif
