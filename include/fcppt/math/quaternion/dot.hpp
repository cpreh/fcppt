//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_DOT_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_DOT_HPP_INCLUDED

#include <boost/math/quaternion.hpp>

namespace fcppt
{
namespace math
{
namespace quaternion
{
/// Calculates the dot product of the two quaternions
template<typename T>
T const
dot(
	boost::math::quaternion<T> const &p,
	boost::math::quaternion<T> const &q)
{
	return
		p.R_component_1()*q.R_component_1() + 
		p.R_component_2()*q.R_component_2() + 
		p.R_component_3()*q.R_component_3() + 
		p.R_component_4()*q.R_component_4();
}
}
}
}

#endif
