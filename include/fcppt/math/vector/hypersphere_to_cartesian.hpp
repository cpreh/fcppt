//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_HYPERSPHERE_TO_CARTESIAN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_HYPERSPHERE_TO_CARTESIAN_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/math/vector/object.hpp>
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

\code
// This code calculates a three-dimensional point from two angles (...of the 3D
// sphere), typically called azimuth an elevation

// The point type
typedef
fcppt::math::vector::static_<float,3>
vector3f;

// The angles type
typedef
fcppt::math::vector::static_<float,2>
vector2f;

vector3f point =
	fcppt::math::vector::hypersphere_to_cartesian(
		vector2f(
			fcppt::math::pi<float>(),
			0.0f));
\endcode

Note that in two dimensions, you have polar coordinates, and so you need one
angle to denote a point on the unit circle. The point then has cartesian coordinates:

<pre>
(cos(angle),sin(angle))
</pre>

Just as expected.

In three dimensions, you need two angles, usually called <em>azimuth</em> and
<em>inclination</em> to denote a point. The resulting point has the following
coordinates:

<pre>
(cos(inclination),cos(azimuth)*sin(inclination),sin(inclination)*sin(azimuth))
</pre>

So, if azimuth and inclination are zero, you get the point (1,0,0). In a
coordinate system where x points to the right, y to the top and z denotes the
"depth" (goes into the screen or out of the screen), you are on the right
boundary of the sphere.

The case where inclination is zero can be considered the sphere's "zenith"
point, meaning a change in azimuth has no effect on the point's coordinate.
This might be counter-intuitive if you're used to a sphere having the zenith
point at the top. The formula for the hyperspherical coordinates, however,
results in this slight "aberration".

If the inclination is not zero, changing the azimuth towards positive infinity
results in a clockwise rotation around the x axis, assuming the viewer looks
down the positive x axis.

Changing the inclination towards positive infinity results in a
counterclockwise rotation around the z axis, assuming the viewer looks down
the positive z axis.
*/
template<typename T,typename N,typename S>
fcppt::math::vector::static_<T,N::value+1> const
hypersphere_to_cartesian(
	fcppt::math::vector::object<T,N,S> const &angles)
{
	typedef
	static_<T,N::value+1>
	result_type;

	typedef typename
	result_type::size_type
	size_type;

	typedef typename
	result_type::value_type
	value_type;

	result_type result{
		fcppt::no_init()
	};

	for(size_type i = 0; i < result.size(); ++i)
	{
		// Hehe..."sins"
		value_type sins =
			fcppt::literal<value_type>(
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
				fcppt::literal<value_type>(1)
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
