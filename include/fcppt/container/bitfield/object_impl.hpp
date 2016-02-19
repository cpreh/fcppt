//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/container/bitfield/object_decl.hpp>
#include <fcppt/container/bitfield/proxy_impl.hpp>
#include <fcppt/container/bitfield/detail/null_array.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::object(
	fcppt::no_init const &
)
// Don't initialize array_
{
}

FCPPT_PP_POP_WARNING

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::object(
	initializer_list_type const &_init
)
:
	array_(
		fcppt::container::bitfield::detail::null_array<
			array_type
		>()
	)
{
	for(
		auto const &elem
		:
		_init
	)
		this->set(
			elem,
			true
		);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::object(
	array_type const &_array
)
:
	array_(
		_array
	)
{
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
typename fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::const_reference
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator[](
	ElementType const _index
) const
{
	return
		const_reference(
			array_,
			this->to_index(
				_index
			)
		);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
typename fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::reference
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator[](
	ElementType const _index
)
{
	return
		reference(
			array_,
			this->to_index(
				_index
			)
		);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
void
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::set(
	ElementType const _index,
	value_type const _value
)
{
	(*this)[
		_index
	] =
		_value;
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::value_type
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::get(
	ElementType const _index
) const
{
	return
		(*this)[
			_index
		];
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
typename
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::array_type &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::array()
{
	return
		array_;
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
typename
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::array_type const &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::array() const
{
	return
		array_;
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::null()
{
	return
		object(
			fcppt::container::bitfield::detail::null_array<
				array_type
			>()
		);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
typename
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::size_type
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::to_index(
	ElementType const _index
)
{
	return
		static_cast<
			size_type
		>(
			_index
		);
}

#endif
