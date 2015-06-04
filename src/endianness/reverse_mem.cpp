//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/endianness/reverse_mem.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>


void
fcppt::endianness::reverse_mem(
	unsigned char *const _data,
	std::size_t const _len
)
{
	for(
		std::size_t const index
		:
		fcppt::make_int_range_count(
			_len
			/
			2
		)
	)
		std::swap(
			_data[
				index
			],
			_data[
				_len
				-
				index
				-
				1u
			]
		);
}
