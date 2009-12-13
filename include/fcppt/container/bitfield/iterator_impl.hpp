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


#ifndef SGE_CONTAINER_BITFIELD_ITERATOR_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_BITFIELD_ITERATOR_IMPL_HPP_INCLUDED

#include <sge/container/bitfield/iterator.hpp>
#include <sge/container/bitfield/proxy_impl.hpp>

template<
	typename StoredType,
	typename Reference,
	sge::container::bitfield::size_type ElementBits
>
sge::container::bitfield::iterator<
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
	sge::container::bitfield::size_type ElementBits
>
void
sge::container::bitfield::iterator<
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
	sge::container::bitfield::size_type ElementBits
>
void
sge::container::bitfield::iterator<
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
	sge::container::bitfield::size_type ElementBits
>
void
sge::container::bitfield::iterator<
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
	sge::container::bitfield::size_type ElementBits
>
bool
sge::container::bitfield::iterator<
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
	sge::container::bitfield::size_type ElementBits
>
Reference
sge::container::bitfield::iterator<
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
	sge::container::bitfield::size_type ElementBits
>
template<
	typename OtherStoredType,
	typename OtherReference
>
sge::container::bitfield::iterator<
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
