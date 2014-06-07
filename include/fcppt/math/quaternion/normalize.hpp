//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_NORMALIZE_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_NORMALIZE_HPP_INCLUDED

#include <fcppt/math/quaternion/dot.hpp>
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
\brief Normalizes a quaternion <code>q</code> by dividing by <code>dot(q,q)</code>
\ingroup fcpptmathquaternion
\tparam T The quaternion's value type (has to be a floating point type)
\note
Behavior is undefined for quaternions with norm zero.
*/
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
