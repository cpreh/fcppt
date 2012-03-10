//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_IS_BIG_ENDIAN_HPP_INCLUDED
#define FCPPT_ENDIANNESS_IS_BIG_ENDIAN_HPP_INCLUDED

#include <fcppt/symbol.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief Returns if this machine uses big endianness

\ingroup fcpptendianness

Equivalent to <code>host_format() == format::big</code>
*/
FCPPT_SYMBOL
bool
is_big_endian();

}
}

#endif
