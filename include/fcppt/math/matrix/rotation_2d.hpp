//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_2D_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_2D_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates a two dimensional rotation matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\param angle The angle to rotate about

The resulting matrix will be a static one.
*/
template<
	typename T
>
typename static_<T, 2, 2>::type const
rotation_2d(
	T const angle
)
{
	T const
		sinx =
			std::sin(
				angle),
		cosx =
			std::cos(
				angle);

	return
		typename static_<T, 2, 2>::type(
			cosx, -sinx,
			sinx,  cosx
		);
}
}
}
}

#endif
