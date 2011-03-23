//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED

#include <fcppt/container/bitfield/proxy.hpp>

template<
	typename StoredType
>
fcppt::container::bitfield::proxy<StoredType>::proxy(
	StoredType _array,
	size_type const _pos
)
:
	array_(_array),
	pos_(_pos)
{}

template<
	typename StoredType
>
fcppt::container::bitfield::size_type
fcppt::container::bitfield::proxy<StoredType>::bit_offset(
	size_type const _pos
)
{
	return _pos % element_bits;
}

template<
	typename StoredType
>
fcppt::container::bitfield::size_type
fcppt::container::bitfield::proxy<StoredType>::array_offset(
	size_type const _pos
)
{
	return _pos / element_bits;
}

template<
	typename StoredType
>
fcppt::container::bitfield::proxy<StoredType> &
fcppt::container::bitfield::proxy<StoredType>::operator=(
	value_type const _value
)
{
	size_type const
		index(
			array_offset(
				pos_
			)
		),
		bit(
			bit_offset(
				pos_
			)
		);

	if(_value)
		array_[index] |= (1u << bit);
        else
		array_[index] &= ~(1u << bit);

	return *this;
}

template<
	typename StoredType
>
fcppt::container::bitfield::proxy<StoredType>::operator
fcppt::container::bitfield::value_type() const
{
	return
		(
			array_[array_offset(pos_)]
			& (1u << (bit_offset(pos_)))
		)
		!= 0u;
}

#endif
