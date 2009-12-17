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


#ifndef FCPPT_MATH_MATRIX_LOOK_AT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_LOOK_AT_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename S
>
typename static_<T, 4, 4>::type const
look_at(
	vector::basic<
		T,
		N,
		S
	> const &eye,
	vector::basic<
		T,
		N,
		S
	> const &location,
	vector::basic<
		T,
		N,
		S
	> const &up
);

}
}
}

#include <fcppt/math/matrix/detail/look_at_impl.hpp>

#endif
