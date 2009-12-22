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


#ifndef FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/intersects.hpp>
#include <fcppt/math/size_type.hpp>
#include <algorithm>

namespace fcppt
{
namespace math
{
namespace box
{

template<
	typename T,
	size_type N
>
basic<T, N> const
intersection(
	basic<T, N> const &a,
	basic<T, N> const &b
)
{
	if(
		!intersects(
			a,
			b
		)
	)
		return basic<T, N>::null();

	basic<T, N> ret;

	for(
		size_type i = 0;
		i < N;
		++i
	)
	{
		ret.pos(
			i,
			std::max(
				a.pos(i),
				b.pos(i)
			)
		);

		ret.dimension(
			i,
			std::min(
				a.max(i),
				b.max(i)
			)
			- ret.pos(i)
		);
	}

	return ret;
}

}
}
}

#endif
