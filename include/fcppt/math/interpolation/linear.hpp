//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERPOLATION_LINEAR_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_LINEAR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace interpolation
{
/// Interpolates between a and b (works only with a floating point
/// parameter)
template<typename Float,typename Value>
typename
boost::enable_if_c
<
	boost::is_floating_point<Float>::value,
	Value const
>::type
linear(
	Float const &f,
	Value const &v1,
	Value const &v2)
{
	return (static_cast<Float>(1) - f) * v1 + f * v2;
}
}
}
}

#endif
