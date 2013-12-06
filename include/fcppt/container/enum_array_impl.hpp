//          Copyright Carl Philipp Reh 2009 - 2013.
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
>::operator[](
	size_type const _index
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
	size_type const _index
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
>::internal::size_type
fcppt::container::enum_array<
	Enum,
	Value
>::to_index(
	size_type const _index
)
{
	return
		fcppt::cast::enum_to_int<
			typename
			internal::size_type
		>(
			_index
		);
}

#endif
