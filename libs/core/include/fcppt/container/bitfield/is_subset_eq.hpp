//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_IS_SUBSET_EQ_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_IS_SUBSET_EQ_HPP_INCLUDED

#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/bitfield/operators.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Checks if one bitfield has all the bits of another bitfield set.

Checks if all bits set in \a _left are also set in \a _right.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
is_subset_eq(
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
		(_left & _right)
		==
		_left;
}

}
}
}

#endif
