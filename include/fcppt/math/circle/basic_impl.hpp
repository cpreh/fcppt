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


#ifndef FCPPT_MATH_CIRCLE_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/circle/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

template<
	typename T
>
fcppt::math::circle::basic<T>::basic(
	point_type const &origin_,
	const_reference radius_)
:
	origin_(origin_),
	radius_(radius_)
{}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::point_type &
fcppt::math::circle::basic<T>::origin()
{
	return origin_;
}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::point_type const &
fcppt::math::circle::basic<T>::origin() const
{
	return origin_;
}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::reference
fcppt::math::circle::basic<T>::radius()
{
	return radius_;
}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::const_reference
fcppt::math::circle::basic<T>::radius() const
{
	return radius_;
}

#endif
