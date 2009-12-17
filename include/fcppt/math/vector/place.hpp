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


#ifndef FCPPT_MATH_VECTOR_PLACE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_PLACE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T
>
typename static_<T, 3>::type const
place(
	T const &radius,
	T const &high_angle,
	T const &plane_angle)
{
	return typename static_<T, 3>::type(
		radius * std::sin(high_angle) * std::cos(plane_angle),
		radius * std::cos(high_angle),
		radius * std::sin(high_angle) * std::sin(plane_angle));
}

}
}
}

#endif
