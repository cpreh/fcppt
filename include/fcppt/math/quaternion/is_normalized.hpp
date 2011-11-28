//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_IS_NORMALIZED_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_IS_NORMALIZED_HPP_INCLUDED

#include <fcppt/math/quaternion/dot.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace quaternion
{
/// Tests if the quaternion has norm 1
template<typename T>
typename
boost::enable_if
<
	boost::is_floating_point<T>,
	bool
>::type
is_normalized(
	boost::math::quaternion<T> const &r,
	T const epsilon)
{
	return
		dot(
			r,
			r) - static_cast<T>(1) < epsilon;
}
}
}
}

#endif
