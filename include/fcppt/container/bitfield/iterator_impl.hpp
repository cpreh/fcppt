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
>::iterator()
:
	array_(),
	pos_()
{}

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
	StoredType _array,
	difference_type const _pos
)
:
	array_(&_array),
	pos_(_pos)
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
	difference_type const _diff
)
{
	pos_ += _diff;
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
	++pos_;
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
	--pos_;
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
	> const &_other
) const
{
	return pos_ == _other.pos_;
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
	return
		proxy<
			StoredType,
			ElementBits
		>(
			*array_,
			static_cast<
				size_type
			>(
				pos_
			)
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
	iterator const &_other
) const
{
	return _other.pos - pos_;
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
	> const &_other
)
:
	array_(_other.array_),
	pos_(_other.pos_)
{}

#endif
