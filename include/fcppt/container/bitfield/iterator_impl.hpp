//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/null_ptr.hpp>
#include <fcppt/container/bitfield/iterator_decl.hpp>
#include <fcppt/container/bitfield/proxy_impl.hpp>


template<
	typename StoredType,
	typename Reference
>
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::iterator()
:
	array_(
		fcppt::null_ptr()
	),
	pos_(
		0
	)
{
}

template<
	typename StoredType,
	typename Reference
>
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::iterator(
	StoredType _array,
	difference_type const _pos
)
:
	array_(
		&_array
	),
	pos_(
		_pos
	)
{
}

template<
	typename StoredType,
	typename Reference
>
void
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::advance(
	difference_type const _diff
)
{
	pos_ += _diff;
}

template<
	typename StoredType,
	typename Reference
>
void
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::increment()
{
	++pos_;
}

template<
	typename StoredType,
	typename Reference
>
void
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::decrement()
{
	--pos_;
}

template<
	typename StoredType,
	typename Reference
>
bool
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::equal(
	iterator<
		StoredType,
		Reference
	> const &_other
) const
{
	return pos_ == _other.pos_;
}

template<
	typename StoredType,
	typename Reference
>
Reference
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::dereference() const
{
	return
		proxy<
			StoredType
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
	typename Reference
>
typename fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::difference_type
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::distance_to(
	iterator const &_other
) const
{
	return _other.pos_ - pos_;
}

template<
	typename StoredType,
	typename Reference
>
template<
	typename OtherStoredType,
	typename OtherReference
>
fcppt::container::bitfield::iterator<
	StoredType,
	Reference
>::iterator(
	iterator<
		OtherStoredType,
		OtherReference
	> const &_other
)
:
	array_(_other.array_),
	pos_(_other.pos_)
{}

#endif
