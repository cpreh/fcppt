//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERPOLATION_LINEAR_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_LINEAR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
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
Value const
linear(
	Float const &f,
	Value const &v1,
	Value const &v2)
{
	static_assert(
		std::is_floating_point<Float>::value,
		"interpolation::linear can only be used on floating point types"
	);

	return (fcppt::literal<Float>(1) - f) * v1 + f * v2;
}
}
}
}

#endif
