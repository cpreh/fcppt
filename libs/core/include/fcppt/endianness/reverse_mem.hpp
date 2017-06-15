//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_REVERSE_MEM_HPP_INCLUDED
#define FCPPT_ENDIANNESS_REVERSE_MEM_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/endianness/raw_pointer.hpp>
#include <fcppt/endianness/size_type.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief Reverses the byte order of a given memory block

\ingroup fcpptendianness

Reverses the byte order of the memory pointed to by \a data and the size of \a
size.

\param data The memory to the memory block

\param size The size of the memory block
*/
FCPPT_DETAIL_SYMBOL
void
reverse_mem(
	fcppt::endianness::raw_pointer data,
	fcppt::endianness::size_type size
);

}
}

#endif
