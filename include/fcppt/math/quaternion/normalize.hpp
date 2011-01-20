//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
/// Normalizes a quaternion q by dividing by dot(q,q)
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
