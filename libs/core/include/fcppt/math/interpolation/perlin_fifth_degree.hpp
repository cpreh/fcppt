//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERPOLATION_PERLIN_FIFTH_DEGREE_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_PERLIN_FIFTH_DEGREE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/interpolation/linear.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace interpolation
{

/**
\brief Interpolates between two values using perlin fifth degree

\ingroup fcpptmath

\tparam Float Must be a floating point type

\tparam Value Must support scalar multiplication with \a Float and addition
*/
template<
	typename Float,
	typename Value
>
Value
perlin_fifth_degree(
	Float const &_f,
	Value const &_v1,
	Value const &_v2
)
{
	static_assert(
		std::is_floating_point<
			Float
		>::value,
		"perlin_fifth_degree can only be used on floating point types"
	);

	return
		fcppt::math::interpolation::linear(
			_f * _f * _f * (
				_f *
				(
					fcppt::literal<Float>(6.0f) * _f
					-
					fcppt::literal<Float>(15.0f)
				)
				+ fcppt::literal<Float>(10.0f)
			),
			_v1,
			_v2
		);
}

}
}
}

#endif

