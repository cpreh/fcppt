//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_UNIT_CIRCLE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_UNIT_CIRCLE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
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

/// Transforms @a angle into a unit vector pointing in that direction
/**
 * @tparam Float must be a floating point type
 * @return The resulting vector will be a two dimensional vector consisting of (cos(angle), sin(angle))
*/
template<
	typename Float
>
typename boost::enable_if<
	boost::is_floating_point<
		Float
	>,
	typename vector::static_<
		Float,
		2
	>::type
>::type
unit_circle(
	Float const angle
)
{
	return
		typename vector::static_<
			Float,
			2
		>::type(
			std::cos(
				angle
			),
			std::sin(
				angle
			)
		);
}

}
}
}

#endif
