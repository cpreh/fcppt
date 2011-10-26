//          Copyright Carl Philipp Reh 2009 - 2011.
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
 * Initializes a quaternion from a scalar and a vector.
 *
 * The vector is _not_ an axis, see from_angle_and_axis for that!
 */
template<typename T>
boost::math::quaternion<T> const
from_scalar_and_vector(
	T const &s,
	typename fcppt::math::vector::static_<T,3>::type const &v)
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
