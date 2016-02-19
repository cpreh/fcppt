//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_COMPARISON_HPP_INCLUDED

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
\brief Compares two bitfields for equality

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator==(
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
		std::equal(
			_left.array().begin(),
			_left.array().end(),
			_right.array().begin()
		);
}

/**
\brief Compares two bitfields for disequality

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator!=(
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
		!(
			_left
			==
			_right
		);
}

/**
\brief Compares two bitfields lexicographically bit by bit.

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator<(
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
		std::lexicographical_compare(
			_left.array().begin(),
			_left.array().end(),
			_right.array().begin(),
			_right.array().end()
		);
}

/**
\brief Compares two bitfields lexicographically bit by bit.

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator<=(
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

/**
\brief Compares two bitfields lexicographically bit by bit.

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator>(
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

/**
\brief Compares two bitfields lexicographically bit by bit.

\ingroup fcpptcontainerbitfield
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator>=(
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

}
}
}

#endif
