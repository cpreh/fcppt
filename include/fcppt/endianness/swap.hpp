//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED
#define FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED

#include <fcppt/endianness/reverse_mem.hpp>

namespace fcppt
{
namespace endianness
{

template<
	typename T
>
T
swap(
	T t
)
{
	reverse_mem(
		reinterpret_cast<
			unsigned char *
		>(
			&t
		),
		sizeof(
			T
		)
	);

	return t;
}
}
}

#endif
