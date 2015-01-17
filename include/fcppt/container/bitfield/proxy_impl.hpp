//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/container/bitfield/proxy_decl.hpp>
#include <fcppt/container/bitfield/value_type.hpp>


template<
	typename StoredType
>
fcppt::container::bitfield::proxy<
	StoredType
>::proxy(
	StoredType _array,
	size_type const _pos
)
:
	array_(
		_array
	),
	pos_(
		_pos
	)
{
}

template<
	typename StoredType
>
typename fcppt::container::bitfield::proxy<
	StoredType
>::size_type
fcppt::container::bitfield::proxy<
	StoredType
>::bit_offset(
	size_type const _pos
)
{
	return _pos % element_bits;
}

template<
	typename StoredType
>
typename fcppt::container::bitfield::proxy<
	StoredType
>::size_type
fcppt::container::bitfield::proxy<
	StoredType
>::array_offset(
	size_type const _pos
)
{
	return _pos / element_bits;
}

template<
	typename StoredType
>
typename fcppt::container::bitfield::proxy<
	StoredType
>::internal_type
fcppt::container::bitfield::proxy<
	StoredType
>::bit_mask(
	size_type const _pos
)
{
	return
		fcppt::literal<
			internal_type
		>(
			1u
		)
		<<
		_pos;
}

template<
	typename StoredType
>
fcppt::container::bitfield::proxy<
	StoredType
> &
fcppt::container::bitfield::proxy<
	StoredType
>::operator=(
	fcppt::container::bitfield::value_type const _value
)
{
	size_type const
		index(
			proxy::array_offset(
				pos_
			)
		),
		bit(
			proxy::bit_offset(
				pos_
			)
		);

	internal_type const mask(
		proxy::bit_mask(
			bit
		)
	);

	if(
		_value
	)
		array_[
			index
		] |=
			mask;
        else
		array_[
			index
		] &=
			~mask;

	return *this;
}

template<
	typename StoredType
>
fcppt::container::bitfield::proxy<
	StoredType
>::operator
fcppt::container::bitfield::value_type() const
{
	return
		(
			array_[
				proxy::array_offset(
					pos_
				)
			]
			&
			proxy::bit_mask(
				proxy::bit_offset(
					pos_
				)
			)
		)
		!= 0u;
}

#endif
