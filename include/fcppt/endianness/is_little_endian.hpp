//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_IS_LITTLE_ENDIAN_HPP_INCLUDED
#define FCPPT_ENDIANNESS_IS_LITTLE_ENDIAN_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief Returns if this machine uses little endianness

\ingroup fcpptendianness

Equivalent to <code>host_format() == format::little</code>
*/
FCPPT_DETAIL_SYMBOL
bool
is_little_endian();

}
}

#endif
