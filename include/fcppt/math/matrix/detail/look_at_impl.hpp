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


#ifndef FCPPT_MATH_MATRIX_DETAIL_LOOK_AT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_LOOK_AT_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/cross.hpp>
#include <fcppt/math/vector/normalize.hpp>
#include <fcppt/math/vector/static.hpp>

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::matrix::static_<T, 4, 4>::type const
fcppt::math::matrix::look_at(
	vector::basic<
		T,
		N,
		S
	> const &eye,
	vector::basic<
		T,
		N,
		S
	> const &lookat,
	vector::basic<
		T,
		N,
		S
	> const &up
)
{
	typedef typename vector::static_<
		T,
		3
	>::type vec3;

	vec3 const
		f(
			normalize(
				lookat - eye
			)
		),
		s(
			cross(
				f,
				normalize(
					up
				)
			)
		),
		u(
			cross(
				s,
				f
			)
		);

	return typename static_<
		T,
		4,
		4
	>::type(
		s.x(), u.x(), -f.x(), 0,
		s.y(), u.y(), -f.y(), 0,
		s.z(), u.z(), -f.z(), 0,
		0, 0, 0, 1
	)
	* translation(
		-eye.x(),
		-eye.y(),
		-eye.z()
	);
}

#endif
