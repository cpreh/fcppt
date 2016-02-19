//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_FROM_ENUM_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_FROM_ENUM_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/container/bitfield/default_internal_type.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Declare a bitfield from an enum

\ingroup fcpptcontainerbitfield

\tparam Enum Must be an enum type

\tparam InternalType The internal type to use for the bitfield
*/
template<
	typename Enum,
	typename InternalType
		= fcppt::container::bitfield::default_internal_type
>
using object_from_enum
=
fcppt::container::bitfield::object<
	Enum,
	typename fcppt::enum_size<
		Enum
	>::type,
	InternalType
>;

}
}
}

#endif
