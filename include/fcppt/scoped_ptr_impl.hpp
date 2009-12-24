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


#ifndef FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/scoped_ptr_decl.hpp>
#include <algorithm>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	pointer const p
)
:
	ptr(p)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	auto_ptr<T> p
)
:
	ptr(p.release())
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::scoped_ptr<T, Deleter>::~scoped_ptr()
{
	Deleter<T>()(ptr);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::reset(
	pointer const p
)
{
	scoped_ptr(p).swap(*this);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::scoped_ptr<T, Deleter>::reference
fcppt::scoped_ptr<T, Deleter>::operator*() const
{
	return *ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::scoped_ptr<T, Deleter>::pointer
fcppt::scoped_ptr<T, Deleter>::operator->() const
{
	return ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::scoped_ptr<T, Deleter>::pointer
fcppt::scoped_ptr<T, Deleter>::get() const
{
	return ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::scoped_ptr<T, Deleter>::operator! () const
{
	return !ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::swap(
	scoped_ptr &b
)
{
	std::swap(
		ptr,
		b.ptr
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::take(
	auto_ptr<T> p
)
{
	reset();
	ptr = p.release();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::scoped_ptr<T, Deleter>::boolean_test() const
{
	return ptr != 0;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::swap(
	scoped_ptr<T, Deleter> &a,
	scoped_ptr<T, Deleter> &b
)
{
	a.swap(b);
}

#endif
