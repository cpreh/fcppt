//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ENUM_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_ENUM_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/container/enum_array_decl.hpp>


template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::reference
fcppt::container::enum_array<
	Enum,
	Value
>::at(
	Enum const _index
)
{
	return
		impl_.at(
			this->to_index(
				_index
			)
		);
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reference
fcppt::container::enum_array<
	Enum,
	Value
>::at(
	Enum const _index
) const
{
	return
		impl_.at(
			this->to_index(
				_index
			)
		);
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::reference
fcppt::container::enum_array<
	Enum,
	Value
>::operator[](
	Enum const _index
)
{
	return
		impl_[
			this->to_index(
				_index
			)
		];
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reference
fcppt::container::enum_array<
	Enum,
	Value
>::operator[](
	Enum const _index
) const
{
	return
		impl_[
			this->to_index(
				_index
			)
		];
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::reference
fcppt::container::enum_array<
	Enum,
	Value
>::front()
{
	return
		impl_.front();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reference
fcppt::container::enum_array<
	Enum,
	Value
>::front() const
{
	return
		impl_.front();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::reference
fcppt::container::enum_array<
	Enum,
	Value
>::back()
{
	return
		impl_.back();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reference
fcppt::container::enum_array<
	Enum,
	Value
>::back() const
{
	return
		impl_.back();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::pointer
fcppt::container::enum_array<
	Enum,
	Value
>::data()
{
	return
		impl_.data();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_pointer
fcppt::container::enum_array<
	Enum,
	Value
>::data() const
{
	return
		impl_.data();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::iterator
fcppt::container::enum_array<
	Enum,
	Value
>::begin()
{
	return
		impl_.begin();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::iterator
fcppt::container::enum_array<
	Enum,
	Value
>::end()
{
	return
		impl_.end();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::cbegin() const
{
	return
		impl_.cbegin();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::cend() const
{
	return
		impl_.cend();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::begin() const
{
	return
		impl_.begin();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::end() const
{
	return
		impl_.end();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::reverse_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::rbegin()
{
	return
		impl_.rbegin();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::reverse_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::rend()
{
	return
		impl_.rend();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reverse_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::crbegin() const
{
	return
		impl_.crbegin();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reverse_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::crend() const
{
	return
		impl_.crend();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reverse_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::rbegin() const
{
	return
		impl_.rbegin();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::const_reverse_iterator
fcppt::container::enum_array<
	Enum,
	Value
>::rend() const
{
	return
		impl_.rend();
}

template<
	typename Enum,
	typename Value
>
bool
fcppt::container::enum_array<
	Enum,
	Value
>::empty() const
{
	return
		impl_.empty();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::size_type
fcppt::container::enum_array<
	Enum,
	Value
>::size() const
{
	return
		impl_.size();
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::size_type
fcppt::container::enum_array<
	Enum,
	Value
>::max_size() const
{
	return
		impl_.max_size();
}

template<
	typename Enum,
	typename Value
>
void
fcppt::container::enum_array<
	Enum,
	Value
>::fill(
	Value const &_value
)
{
	impl_.fill(
		_value
	);
}

template<
	typename Enum,
	typename Value
>
void
fcppt::container::enum_array<
	Enum,
	Value
>::swap(
	enum_array &_other
)
{
	impl_.swap(
		_other.impl_
	);
}

template<
	typename Enum,
	typename Value
>
typename
fcppt::container::enum_array<
	Enum,
	Value
>::internal::size_type
fcppt::container::enum_array<
	Enum,
	Value
>::to_index(
	Enum const _index
)
{
	return
		fcppt::cast::enum_to_int<
			size_type
		>(
			_index
		);
}

// \cond
template<
	typename Enum,
	typename Value
>
void
fcppt::container::swap(
	fcppt::container::enum_array<
		Enum,
		Value
	> &_left,
	fcppt::container::enum_array<
		Enum,
		Value
	> &_right
)
{
	_left.swap(
		_right
	);
}
// \endcond

#endif
