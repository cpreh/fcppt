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


#ifndef FCPPT_VARIANT_RECURSIVE_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_RECURSIVE_IMPL_HPP_INCLUDED

#include <fcppt/variant/recursive_decl.hpp>
#include <algorithm>

template<
	typename T
>
fcppt::variant::recursive<T>::recursive(
	T const &other
)
:
	rep_(
		copy(
			other
		)
	)
{
}

template<
	typename T
>
fcppt::variant::recursive<T>::recursive(
	recursive const &other
)
:
	rep_(
		copy(
			other.get()
		)
	)
{
}

template<
	typename T
>
fcppt::variant::recursive<T> &
fcppt::variant::recursive<T>::operator =(
	T const &other
)
{
	*rep_ = other;

	return *this;
}

template<
	typename T
>
fcppt::variant::recursive<T> &
fcppt::variant::recursive<T>::operator =(
	recursive const &other
)
{
	*rep_ = other.get();

	return *this;
}

template<
	typename T
>
fcppt::variant::recursive<T>::~recursive()
{
	delete rep_;
}

template<
	typename T
>
void
fcppt::variant::recursive<T>::swap(
	recursive &other
)
{
	std::swap(
		rep_,
		other.rep_
	);
}

template<
	typename T
>
T &
fcppt::variant::recursive<T>::get() const
{
	return *rep_;
}

template<
	typename T
>
T *
fcppt::variant::recursive<T>::copy(
	T const &other
)
{
	return new T(other);
}

template<
	typename T
>
void
fcppt::variant::swap(
	recursive<T> &a,
	recursive<T> &b
)
{
	a.swap(
		b
	);
}

#endif
