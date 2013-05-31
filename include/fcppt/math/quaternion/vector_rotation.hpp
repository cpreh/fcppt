//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUATERNION_VECTOR_ROTATION_HPP_INCLUDED
#define FCPPT_MATH_QUATERNION_VECTOR_ROTATION_HPP_INCLUDED

#include <fcppt/literal.hpp>
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
\brief Rotates a static vector using a quaternion
\ingroup fcpptmathquaternion
\tparam T The quaternion's value type (has to be a floating point type)
*/
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
		fcppt::literal<T>(
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
			result.R_component_2(),
			result.R_component_3(),
			result.R_component_4());
}
}
}
}

#endif
