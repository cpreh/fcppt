//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ORTHOGONAL_XY_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ORTHOGONAL_XY_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates a matrix that does an orthogonal projection on the xy place
template<
	typename T
>
typename static_<T, 4, 4>::type const
orthogonal_xy()
{
	T const
		one(
			static_cast<T>(1)
		),
		zero(
			static_cast<T>(0)
		);

	return
		typename static_<T, 4, 4>::type(
			one, zero, zero, zero,
			zero, one, zero, zero,
			zero, zero, zero, zero,
			zero, zero, zero, one
		);
}

}
}
}

#endif
