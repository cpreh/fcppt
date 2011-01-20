//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_COPY_SWAPPED_HPP_INCLUDED
#define FCPPT_ENDIANNESS_COPY_SWAPPED_HPP_INCLUDED

#include <fcppt/endianness/reverse_mem.hpp>

namespace fcppt
{
namespace endianness
{

template<
	typename T,
	typename Size
>
T *
copy_swapped(
	T const * beg,
	T const *const end,
	T *dest,
	Size const stride)
{
	Size counter = 0;

	while(beg != end)
	{
		*dest++ = *beg++;
		if(++counter == stride)
		{
			reverse_mem(
				reinterpret_cast<
					unsigned char *
				>(
					dest - stride
				),
				stride * sizeof(T)
			);
			counter = 0;
		}
	}

	return dest;
}

}
}

#endif
