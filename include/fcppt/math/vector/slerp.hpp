#ifndef FCPPT_MATH_VECTOR_SLERP_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SLERP_HPP_INCLUDED

#include <fcppt/math/vector/basic.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace vector
{
/// See http://en.wikipedia.org/wiki/Slerp
template<typename T,typename N,typename S>
basic<T,N,S> const 
slerp(
	basic<T,N,S> const &start,
	basic<T,N,S> const &end,
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

	// We divide by sin(omega) below, so watch out
	if (fcppt::math::almost_zero(sinomega))
		return start;

	return 
		std::sin((static_cast<T>(1)-t) * omega) / sinomega * start + 
		std::sin(t * omega) / sinomega * end;
}
}
}
}

#endif
