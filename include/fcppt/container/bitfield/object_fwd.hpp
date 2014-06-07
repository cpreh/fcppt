//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/container/bitfield/default_internal_type.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename ElementType,
	typename NumElements,
	typename InternalType =
		fcppt::container::bitfield::default_internal_type
>
class object;

}
}
}

#endif
