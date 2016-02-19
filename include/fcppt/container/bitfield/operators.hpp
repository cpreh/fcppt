//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OPERATORS_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OPERATORS_HPP_INCLUDED

#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Set a bit to true

\ingroup fcpptcontainerbitfield
*/
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
operator|=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &_left,
	ElementType const _index
)
{
	_left.set(
		_index,
		true
	);

	return
		_left;
}

/**
\brief Do a bit-wise "or" for all bits.

\ingroup fcpptcontainerbitfield
*/
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
operator|=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	std::transform(
		_left.array().begin(),
		_left.array().end(),
		_right.array().begin(),
		_left.array().begin(),
		[](
			InternalType const _arg1,
			InternalType const _arg2
		)
		{
			return
				_arg1 | _arg2;
		}
	);

	return
		_left;
}

/**
\brief Do a bit-wise "and" for all bits.

\ingroup fcpptcontainerbitfield
*/
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
operator&=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	std::transform(
		_left.array().begin(),
		_left.array().end(),
		_right.array().begin(),
		_left.array().begin(),
		[](
			InternalType const _arg1,
			InternalType const _arg2
		)
		{
			return
				_arg1 & _arg2;
		}
	);

	return
		_left;
}

/**
\brief Do a bit-wise "xor" for all bits.

\ingroup fcpptcontainerbitfield
*/
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
operator^=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &_left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	std::transform(
		_left.array().begin(),
		_left.array().end(),
		_right.array().begin(),
		_left.array().begin(),
		[](
			InternalType const _arg1,
			InternalType const _arg2
		)
		{
			return
				_arg1 ^ _arg2;
		}
	);

	return
		_left;
}

/**
\brief Do a bit-wise "not" for all bits (inverts all bits)

\ingroup fcpptcontainerbitfield
*/
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
operator~(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> _field
)
{
	std::transform(
		_field.array().begin(),
		_field.array().end(),
		_field.array().begin(),
		[](
			InternalType const _arg
		)
		{
			return
				~_arg;
		}
	);

	return
		_field;
}

/**
\brief Checks if the specified bit is set.

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::value_type
operator&(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_field,
	ElementType const _index
)
{
	return
		_field.get(
			_index
		);
}

/**
\brief Set the specified bit to true

\ingroup fcpptcontainerbitfield
*/
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
operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> _field,
	ElementType const _index
)
{
	return
		_field
		|=
		_index;
}

/**
\brief Do a bit-wise "or" for all bits.

\ingroup fcpptcontainerbitfield
*/
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
operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> _left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		_left
		|=
		_right;
}

/**
\brief Do a bit-wise "and" for all bits.

\ingroup fcpptcontainerbitfield
*/
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
operator&(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> _left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		_left
		&=
		_right;
}

/**
\brief Do a bit-wise "xor" for all bits.

\ingroup fcpptcontainerbitfield
*/
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
operator^(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> _left,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_right
)
{
	return
		_left
		^=
		_right;
}

}
}
}

#endif
