//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
