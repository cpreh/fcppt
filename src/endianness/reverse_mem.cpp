//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/reverse_mem.hpp>
#include <algorithm>

void
fcppt::endianness::reverse_mem(
	unsigned char *const t,
	std::size_t const len
)
{
	for(
		std::size_t i = 0;
		i < len / 2;
		++i
	)
		std::swap(
			t[i],
			t[len-i-1]
		);
}
