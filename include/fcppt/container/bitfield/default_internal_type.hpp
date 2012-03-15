//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DEFAULT_INTERNAL_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DEFAULT_INTERNAL_TYPE_HPP_INCLUDED

namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief The default (unsigned) type to hold the bitfield's bits.

An array of these values is created to hold all bits specified, so a bitfield
cannot "overflow".

\see fcppt::container::bitfield::array
*/
typedef unsigned default_internal_type;

}
}
}

#endif
