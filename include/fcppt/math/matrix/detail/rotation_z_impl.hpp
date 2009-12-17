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


#ifndef FCPPT_MATH_MATRIX_DETAIL_ROTATION_Z_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROTATION_Z_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <cmath>

template<
	typename T
>
typename fcppt::math::matrix::static_<T, 4, 4>::type const
fcppt::math::matrix::rotation_z(
	T const angle)
{
	T const
		sinx = std::sin(angle),
		cosx = std::cos(angle);

	return typename static_<T, 4, 4>::type(
		cosx,  -sinx, static_cast<T>(0), static_cast<T>(0),
		sinx,   cosx, static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
	);
}

#endif
