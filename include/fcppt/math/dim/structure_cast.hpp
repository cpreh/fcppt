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


#ifndef FCPPT_MATH_DIM_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DIM_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/detail/structure_cast.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
Dest const
structure_cast(
	basic<T, N, S> const &src)
{
	return math::detail::structure_cast<
		Dest
	>(
		src
	);

}

}
}
}

#endif
