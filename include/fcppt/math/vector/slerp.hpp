//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SLERP_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SLERP_HPP_INCLUDED

#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Calculates the angle between two arbitrary vector types
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>. Must be a floating point type.
\tparam N The vector's dimension type
\tparam S The vector's storage type
\param start The first vector
\param end The second vector
\param t The interpolation value. Must be inside [0,1].

Does spherical interpolation between two vectors. See

http://en.wikipedia.org/wiki/Slerp

for more information.

\warning
The behaviour is undefined if \p start or \p end are nearly identical.
*/
template<typename T,typename N,typename S>
typename
boost::enable_if
<
	boost::is_floating_point<T>,
	object<T,N,S> const
>::type
slerp(
	object<T,N,S> const &start,
	object<T,N,S> const &end,
	T const t)
{
	// acos of the angle between start and end. We need a function for
	// this, too!
	T const
		omega =
			std::acos(
				fcppt::math::vector::dot(start,end)/
				(fcppt::math::vector::length(start)*fcppt::math::vector::length(end))),
		sinomega =
			std::sin(omega);

	return
		std::sin((static_cast<T>(1)-t) * omega) / sinomega * start +
		std::sin(t * omega) / sinomega * end;
}
}
}
}

#endif
