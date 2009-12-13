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


#ifndef SGE_OPTIONAL_IMPL_HPP_INCLUDED
#define SGE_OPTIONAL_IMPL_HPP_INCLUDED

#include <sge/optional.hpp>
#include <new>

template<
	typename T
>
sge::optional<T>::optional()
:
	storage_(),
	data_(0)
{}


template<
	typename T
>
sge::optional<T>::optional(
	const_reference ref)
:
	storage_(),
	data_(
		construct(ref)
	)
{}

template<
	typename T
>
sge::optional<T>::optional(
	optional const &o)
:
	storage_(),
	data_(
		construct(o)
	)
{}

template<
	typename T
>
sge::optional<T> &
sge::optional<T>::operator=(
	optional const &o)
{
	destroy();
	data_ = construct(o);
	return *this;
}

template<
	typename T
>
sge::optional<T> &
sge::optional<T>::operator=(
	const_reference r)
{
	destroy();
	data_ = construct(r);
	return *this;
}

template<
	typename T
>
sge::optional<T>::~optional()
{
	destroy();
}

template<
	typename T
>
typename sge::optional<T>::reference
sge::optional<T>::operator*()
{
	return *data_;
}

template<
	typename T
>
typename sge::optional<T>::const_reference
sge::optional<T>::operator*() const
{
	return *data_;
}

template<
	typename T
>
typename sge::optional<T>::pointer
sge::optional<T>::operator->()
{
	return data_;
}

template<
	typename T
>
typename sge::optional<T>::const_pointer
sge::optional<T>::operator->() const
{
	return data_;
}

template<
	typename T
>
void
sge::optional<T>::reset()
{
	destroy();
	data_ = 0;
}

template<
	typename T
>
bool
sge::optional<T>::boolean_test() const
{
	return data_;
}

template<
	typename T
>
typename sge::optional<T>::pointer
sge::optional<T>::construct(
	const_reference r)
{
	return data_ = new (storage_.data()) T(r);
}

template<
	typename T
>
typename sge::optional<T>::pointer
sge::optional<T>::construct(
	optional const &o)
{
	return o.data_
		? new (storage_.data()) T(*o)
		: static_cast<pointer>(0);
}

template<
	typename T
>
void
sge::optional<T>::destroy()
{
	if(data_)
		data_->~T();
}

#endif
