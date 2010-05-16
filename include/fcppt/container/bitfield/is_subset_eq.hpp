//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_IS_SUBSET_EQ_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_IS_SUBSET_EQ_HPP_INCLUDED

#include <fcppt/container/bitfield/basic_impl.hpp>

namespace fcppt
{
namespace container
{
namespace bitfield
{

/// Checks if @a left is a subset of @a right or if both are equal
template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
is_subset_eq(
	basic<
		Enum,
		Size,
		InternalType
	> const &left,
	basic<
		Enum,
		Size,
		InternalType
	> const &right
)
{
	return
		(left & right)
		== left;
}

}
}
}

#endif
