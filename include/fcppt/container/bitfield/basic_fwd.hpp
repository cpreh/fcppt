//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_BASIC_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_BASIC_FWD_HPP_INCLUDED

#include <fcppt/container/bitfield/default_internal_type.hpp>

namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename Enum,
	Enum Size,
	typename InternalType =
		bitfield::default_internal_type
>
class basic;

}
}
}

#endif
