//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
	size_type const pos
)
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
	difference_type const d
)
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
	> const &r
) const
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
typename fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::difference_type
fcppt::container::bitfield::iterator<
	StoredType,
	Reference,
	ElementBits
>::distance_to(
	iterator const &other
) const
{
	return other.pos - pos;
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
	> const &r
)
:
	array(r.array),
	pos(r.pos)
{}

#endif
