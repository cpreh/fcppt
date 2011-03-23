//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ORTHOGONAL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ORTHOGONAL_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/box/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/// Calculates a matrix that does an orthogonal projection
/// See also http://www.opengl.org/sdk/docs/man/xhtml/glOrtho.xml
template<
	typename T
>
typename static_<T, 4, 4>::type const
orthogonal(
	T const left,
	T const right,
	T const bottom,
	T const top,
	T const near,
	T const far
)
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
			static_cast<T>(2)/(right-left), zero, zero, -(right + left)/(right-left),
			zero, static_cast<T>(2)/(top-bottom), zero, -(top + bottom)/(top-bottom),
			zero, zero, static_cast<T>(-2)/(far-near), -(far + near)/(far-near),
			zero, zero, zero, one
		);
}

template<
	typename T
>
typename static_<T, 4, 4>::type const
orthogonal(
	math::box::basic<
		T,
		2
	> const &_box,
	T const _near,
	T const _far
)
{
	return
		matrix::orthogonal(
			_box.left(),
			_box.right(),
			_box.bottom(),
			_box.top(),
			_near,
			_far
		);
}

}
}
}

#endif
