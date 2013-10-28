//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/bitfield/iterator_impl.hpp>
#include <fcppt/container/bitfield/object_decl.hpp>
#include <fcppt/container/bitfield/proxy_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


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
	ElementType const _index
)
// Don't initialize array_
{
	this->clear();

	this->set(
		_index,
		true
	);
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
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator=(
	ElementType const _index
)
{
	this->clear();

	this->set(
		_index,
		true
	);

	return *this;
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
>::pointer
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::data()
{
	return
		array_.data();
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
>::const_pointer
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::data() const
{
	return
		array_.data();
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
>::iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::begin()
{
	return
		iterator(
			array_,
			0
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
>::const_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::begin() const
{
	return
		const_iterator(
			array_,
			0
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
>::iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::end()
{
	return
		iterator(
			array_,
			fcppt::cast::to_signed(
				this->size()
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
>::const_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::end() const
{
	return
		const_iterator(
			array_,
			fcppt::cast::to_signed(
				this->size()
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
>::reverse_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::rbegin()
{
	return
		reverse_iterator(
			this->end()
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
>::const_reverse_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::rbegin() const
{
	return
		const_reverse_iterator(
			this->end()
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
>::reverse_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::rend()
{
	return
		reverse_iterator(
			this->begin()
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
>::const_reverse_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::rend() const
{
	return
		const_reverse_iterator(
			this->begin()
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
>::const_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::cbegin() const
{
	return
		this->begin();
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
>::const_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::cend() const
{
	return
		this->end();
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
>::const_reverse_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::crbegin() const
{
	return
		this->rbegin();
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
>::const_reverse_iterator
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::crend() const
{
	return
		this->rend();
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
>::size_type
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::size() const
{
	return static_size::value;
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
		*(
			this->begin()
			+
			static_cast<
				typename
				std::iterator_traits<
					typename
					array_type::const_iterator
				>::difference_type
			>(
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
		*(
			this->begin()
			+
			static_cast<
				typename
				std::iterator_traits<
					typename
					array_type::const_iterator
				>::difference_type
			>(
				_index
			)
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
> &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator|=(
	ElementType const _index
)
{
	this->set(
		_index,
		true
	);

	return *this;
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
> &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator|=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_other
)
{
	std::transform(
		array_.begin(),
		array_.end(),
		_other.array_.begin(),
		array_.begin(),
		[](
			InternalType const _arg1,
			InternalType const _arg2
		)
		{
			return
				_arg1 | _arg2;
		}
	);

	return *this;
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
> &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator&=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_other
)
{
	std::transform(
		array_.begin(),
		array_.end(),
		_other.array_.begin(),
		array_.begin(),
		[](
			InternalType const _arg1,
			InternalType const _arg2
		)
		{
			return
				_arg1 & _arg2;
		}
	);

	return *this;
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
> &
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator^=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_other
)
{
	std::transform(
		array_.begin(),
		array_.end(),
		_other.array_.begin(),
		array_.begin(),
		[](
			InternalType const _arg1,
			InternalType const _arg2
		)
		{
			return
				_arg1 ^ _arg2;
		}
	);

	return *this;
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
> const
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator~() const
{
	object ret{
		fcppt::no_init()
	};

	std::transform(
		array_.begin(),
		array_.end(),
		ret.array_.begin(),
		[](
			InternalType const _arg
		)
		{
			return
				~_arg;
		}
	);

	return ret;
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
>::operator bool() const
{
	return
		fcppt::algorithm::contains_if(
			array_.begin(),
			array_.end(),
			[](
				InternalType const _arg
			)
			{
				return
					_arg != 0;
			}
		);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator==(
	object const &_other
) const
{
	return
		std::equal(
			array_.begin(),
			array_.end(),
			_other.array_.begin()
		);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::operator<(
	object const &_other
) const
{
	return
		std::lexicographical_compare(
			array_.begin(),
			array_.end(),
			_other.array_.begin(),
			_other.array_.end()
		);
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
>::operator&(
	ElementType const _index
) const
{
	return
		this->get(
			_index
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
void
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::clear()
{
	array_.fill(
		0
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
void
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::swap(
	object &_other
)
{
	std::swap(
		array_,
		_other.array_
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
> const
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::null()
{
	object ret{
		fcppt::no_init()
	};

	ret.clear();

	return ret;
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
> const
fcppt::container::bitfield::operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_field,
	ElementType const _index
)
{
	return
		fcppt::container::bitfield::object<
			ElementType,
			NumElements,
			InternalType
		>(
			_field
		)
		|= _index;
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
> const
fcppt::container::bitfield::operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		fcppt::container::bitfield::object<
			ElementType,
			NumElements,
			InternalType
		>(
			_left
		)
		|= _right;
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
> const
fcppt::container::bitfield::operator&(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		fcppt::container::bitfield::object<
			ElementType,
			NumElements,
			InternalType
		>(
			_left
		)
		&= _right;
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
> const
fcppt::container::bitfield::operator^(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		fcppt::container::bitfield::object<
			ElementType,
			NumElements,
			InternalType
		>(
			_left
		)
		^= _right;
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
void
fcppt::container::bitfield::swap(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &_right
)
{
	_left.swap(
		_right
	);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
fcppt::container::bitfield::operator!=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		!(_left == _right);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
fcppt::container::bitfield::operator<=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		!(_left > _right);
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
fcppt::container::bitfield::operator>(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		_right < _left;
}

template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
fcppt::container::bitfield::operator>=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		!(_left < _right);
}

#endif
