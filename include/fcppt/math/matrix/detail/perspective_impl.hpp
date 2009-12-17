/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_MATH_MATRIX_DETAIL_PERSPECTIVE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_PERSPECTIVE_IMPL_HPP_INCLUDED

#include <fcppt/math/compare.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <cmath>

template<
	typename T
>
typename fcppt::math::matrix::static_<T, 4, 4>::type const
fcppt::math::matrix::perspective(
	T const aspect,
	T const fov,
	T const near,
	T const far)
{
	if(compare(far, near))
		throw exception(
			FCPPT_TEXT("matrix::perspective(): far may not be near!")
		);

	if(almost_zero(near))
		throw exception(
			FCPPT_TEXT("matrix::perspective(): near must not be 0!")
		);

	T const
		h = static_cast<T>(1) / std::tan(fov / static_cast<T>(2)),
		w = h / aspect,
		q = (far + near) / (near - far),
		p = static_cast<T>(2) * far * near / (near - far),
		zero = static_cast<T>(0);

	return typename static_<T, 4, 4>::type
	       (w, zero, zero, zero,
	        zero, h, zero, zero,
	        zero, zero, q, static_cast<T>(-1),
	        zero, zero, p, zero);
}

#endif
