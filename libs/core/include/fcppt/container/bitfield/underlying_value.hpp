//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_UNDERLYING_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_UNDERLYING_VALUE_HPP_INCLUDED

#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Returns the underlying value of a bitfield.

\ingroup fcpptcontainerbitfield

Returns the underlying value of \a _bitfield. This function can only be called
if the bitfield consists of exactly one underlying value (which means that
<code>_bitfield::array_size::value == 1u</code>).

\tparam NumElements Must fit into exactly one object of type \a InternalType.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
typename fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
>::internal_type
underlying_value(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &_bitfield
)
{
	static_assert(
		fcppt::container::bitfield::object<
			ElementType,
			NumElements,
			InternalType
		>::array_size::value
		==
		1u,
		"underlying_type can only be used on bitfields with a size of 1"
	);

	return
		std::get<
			0
		>(
			_bitfield.array()
		);
}

}
}
}

#endif
