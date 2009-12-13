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


#ifndef SGE_STRONG_TYPEDEF_IMPL_HPP_INCLUDED
#define SGE_STRONG_TYPEDEF_IMPL_HPP_INCLUDED

#include <sge/strong_typedef_decl.hpp>
#include <sge/detail/strong_typedef_cast.hpp>

template<
	typename T,
	typename Tag
>
sge::strong_typedef<
	T,
	Tag
>::strong_typedef()
:
	t()
{}

template<
	typename T,
	typename Tag
>
template<
	typename U
>
sge::strong_typedef<
	T,
	Tag
>::strong_typedef(
	U const &u
)
:
	t(
		detail::strong_typedef_cast<
			T
		>(
			u
		)
	)
{}

template<
	typename T,
	typename Tag
>
template<
	typename U
>
sge::strong_typedef<
	T,
	Tag
> &
sge::strong_typedef<
	T,
	Tag
>::operator=(
	U const &u
)
{
	t =
		detail::strong_typedef_cast<
			T
		>(
			u
		);

	return *this;
}

template<
	typename T,
	typename Tag
>
sge::strong_typedef<
	T,
	Tag
>::operator T &()
{
	return t;
}

template<
	typename T,
	typename Tag
>
sge::strong_typedef<
	T,
	Tag
>::operator T const &() const
{
	return t;
}


template<
	typename T,
	typename Tag
>
bool
sge::strong_typedef<
	T,
	Tag
>::operator < (
	strong_typedef<
		T,
		Tag
	> const &other
) const
{
	return t < other.t;
}

#endif
