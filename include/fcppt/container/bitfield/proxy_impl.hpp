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


#ifndef SGE_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED

#include <sge/container/bitfield/proxy.hpp>

template<
	typename StoredType,
	sge::container::bitfield::size_type ElementBits
>
sge::container::bitfield::proxy<StoredType, ElementBits>::proxy(
	StoredType array,
	size_type const pos)
:
	array(array),
	pos(pos)
{}

template<
	typename StoredType,
	sge::container::bitfield::size_type ElementBits
>
sge::container::bitfield::size_type
sge::container::bitfield::proxy<StoredType, ElementBits>::bit_offset(
	size_type const p)
{
	return p % ElementBits;
}

template<
	typename StoredType,
	sge::container::bitfield::size_type ElementBits
>
sge::container::bitfield::size_type
sge::container::bitfield::proxy<StoredType, ElementBits>::array_offset(
	size_type const p)
{
	return p / ElementBits;
}

template<
	typename StoredType,
	sge::container::bitfield::size_type ElementBits
>
sge::container::bitfield::proxy<StoredType, ElementBits> &
sge::container::bitfield::proxy<StoredType, ElementBits>::operator=(
	value_type const b)
{
	size_type const
		index(
			array_offset(pos)
		),
		bit(
			bit_offset(pos)
		);

	if(b)
		array[index] |= (1 << bit);
        else
		array[index] &= ~(1 << bit);

	return *this;
}

template<
	typename StoredType,
	sge::container::bitfield::size_type ElementBits
>
sge::container::bitfield::proxy<StoredType, ElementBits>::operator
sge::container::bitfield::value_type() const
{
	return array[array_offset(pos)] & (1 << (bit_offset(pos)));
}

#endif
