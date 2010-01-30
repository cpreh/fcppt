//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED

#include <fcppt/container/bitfield/proxy.hpp>

template<
	typename StoredType,
	fcppt::container::bitfield::size_type ElementBits
>
fcppt::container::bitfield::proxy<StoredType, ElementBits>::proxy(
	StoredType array,
	size_type const pos)
:
	array(array),
	pos(pos)
{}

template<
	typename StoredType,
	fcppt::container::bitfield::size_type ElementBits
>
fcppt::container::bitfield::size_type
fcppt::container::bitfield::proxy<StoredType, ElementBits>::bit_offset(
	size_type const p)
{
	return p % ElementBits;
}

template<
	typename StoredType,
	fcppt::container::bitfield::size_type ElementBits
>
fcppt::container::bitfield::size_type
fcppt::container::bitfield::proxy<StoredType, ElementBits>::array_offset(
	size_type const p)
{
	return p / ElementBits;
}

template<
	typename StoredType,
	fcppt::container::bitfield::size_type ElementBits
>
fcppt::container::bitfield::proxy<StoredType, ElementBits> &
fcppt::container::bitfield::proxy<StoredType, ElementBits>::operator=(
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
	fcppt::container::bitfield::size_type ElementBits
>
fcppt::container::bitfield::proxy<StoredType, ElementBits>::operator
fcppt::container::bitfield::value_type() const
{
	return array[array_offset(pos)] & (1 << (bit_offset(pos)));
}

#endif
