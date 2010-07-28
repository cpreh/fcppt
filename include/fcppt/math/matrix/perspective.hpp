//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_PERSPECTIVE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_PERSPECTIVE_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/math/exception.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/text.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates a perspective matrix
/**
 * @param aspect The screens aspect ratio. It should be (w > h) ? w / h : h / w
 * @param fov The field of view as an angle.
 * @param near The near clipping plane
 * @param far The far clipping plane
 *
 * @remarks near and far should not be the same. near should not be zero.
*/
template<
	typename T
>
typename static_<T, 4, 4>::type const
perspective(
	T const aspect,
	T const fov,
	T const near,
	T const far
)
{
	if(compare(far, near))
		throw math::exception(
			FCPPT_TEXT("matrix::perspective(): far may not be near!")
		);

	if(almost_zero(near))
		throw math::exception(
			FCPPT_TEXT("matrix::perspective(): near must not be 0!")
		);

	T const
		h = static_cast<T>(1) / std::tan(fov / static_cast<T>(2)),
		w = h / aspect,
		q = (far + near) / (near - far),
		p = static_cast<T>(2) * far * near / (near - far),
		zero = static_cast<T>(0);

	return
		typename static_<T, 4, 4>::type
		(
			w, zero, zero,                  zero,
			zero, h, zero,                  zero,
			zero, zero, q,                  p,
			zero, zero, static_cast<T>(-1), zero
		);

}

}
}
}

#endif
