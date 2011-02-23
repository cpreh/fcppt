//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/reverse_mem.hpp>
#include <algorithm>

void
fcppt::endianness::reverse_mem(
	unsigned char *const _data,
	std::size_t const _len
)
{
	for(
		std::size_t i = 0;
		i < _len / 2;
		++i
	)
		std::swap(
			_data[i],
			_data[_len - i - 1]
		);
}
