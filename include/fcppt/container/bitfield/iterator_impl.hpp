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


#ifndef FCPPT_CONTAINER_BITFIELD_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/container/bitfield/iterator.hpp>
#include <fcppt/container/bitfield/proxy_impl.hpp>

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::iterator(
	StoredType array,
	size_type const pos)
:
	array(array),
	pos(pos)
{}

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
void
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::advance(
	difference_type const d)
{
	pos += d;
}

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
void
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::increment()
{
	++pos;
}

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
void
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::decrement()
{
	--pos;
}

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
bool
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::equal(
	iterator<
		StoredType,
		Reference,
		ElementBits
	> const &r) const
{
	return pos == r.pos;
}

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
Reference
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::dereference() const
{
	return proxy<
		StoredType,
		ElementBits
	>(
		array,
		pos
	);
}

template<
	typename StoredType,
	typename Reference,
	fcppt::container::bitfield::size_type ElementBits
>
template<
	typename OtherStoredType,
	typename OtherReference
>
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::iterator(
	iterator<
		OtherStoredType,
		OtherReference,
		ElementBits
	> const &r)
:
	array(r.array),
	pos(r.pos)
{}

#endif
