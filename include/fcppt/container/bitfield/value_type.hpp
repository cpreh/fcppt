//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_VALUE_TYPE_HPP_INCLUDED


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief The type denoting a single bit

This is currently a boolean, but might be subject to change due to bool's
"likeliness" to implicitly convert to other types (and the other way round).
*/
typedef bool value_type;

}
}
}

#endif
