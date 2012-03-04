//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_HYPERSPHERE_TO_CARTESIAN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_HYPERSPHERE_TO_CARTESIAN_HPP_INCLUDED

#include <fcppt/math/vector/basic.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Calculate the n dimensional polar coordinates, also called "hyperspherical coordinates"
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type
\tparam S The vector's storage type
\param angles An \p N-1 dimensional vector containing the angles in each dimension

The formula is taken from:

http://en.wikipedia.org/wiki/Hypersphere#Hyperspherical_coordinates

Given an (n-1)-dimensional angle vector this returns an n-dimensional unit
vector in n-dimensional cartesian coordinates. If you want a scaled version of
the result, do it yourself using <code>operator*(T,vector)</code>.

Example:

\code{.cpp}
// This code calculates a three-dimensional point from two angles (...of the 3D
// sphere), typically called azimuth an elevation

// The point type
typedef
fcppt::math::vector::static_<float,3>::type
vector3f;

// The angles type
typedef
fcppt::math::vector::static_<float,2>::type
vector2f;

vector3f point =
	fcppt::math::vector::hypersphere_to_cartesian(
		vector2f(
			fcppt::math::pi<float>(),
			0.0f));
\endcode
*/
template<typename T,typename N,typename S>
typename
static_<T,N::value+1>::type const
hypersphere_to_cartesian(
	basic<T,N,S> const &angles)
{
	typedef typename
	static_<T,N::value+1>::type
	result_type;

	typedef typename
	result_type::size_type
	size_type;

	typedef typename
	result_type::value_type
	value_type;

	result_type result;
	for(size_type i = 0; i < result.size(); ++i)
	{
		// Hehe..."sins"
		value_type sins =
			static_cast<value_type>(
				1);
		for(size_type j = 0; j < i; ++j)
			sins *=
				std::sin(
					angles[j]);
		result[i] =
			sins *
			(
			i >= angles.size()
			?
				static_cast<value_type>(1)
			:
				std::cos(
					angles[i]));
	}
	return result;
}
}
}
}

#endif
