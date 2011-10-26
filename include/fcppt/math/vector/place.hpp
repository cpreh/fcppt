//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_PLACE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_PLACE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
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

template<
	typename T
>
typename static_<T, 3>::type const
place(
	T const &radius,
	T const &high_angle,
	T const &plane_angle
)
{
	return
		typename static_<T, 3>::type(
			radius * std::sin(high_angle) * std::cos(plane_angle),
			radius * std::cos(high_angle),
			radius * std::sin(high_angle) * std::sin(plane_angle)
		);
}

}
}
}

#endif
