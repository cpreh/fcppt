//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_ROTATION_Y_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROTATION_Y_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <cmath>

template<
	typename T
>
typename fcppt::math::matrix::static_<T, 4, 4>::type const
fcppt::math::matrix::rotation_y(
	T const angle)
{
	T const
		sinx = std::sin(angle),
		cosx = std::cos(angle);

	return typename static_<T, 4, 4>::type(
		cosx, static_cast<T>(0), -sinx, static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
		sinx, static_cast<T>(0),  cosx, static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
	);
}

#endif
