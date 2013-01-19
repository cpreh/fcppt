//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[rawvector
#include <fcppt/text.hpp>
#include <fcppt/container/raw_vector.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace
{

// read at most count bytes in p,
// return the number of bytes read
std::size_t
read(
	unsigned char *p,
	std::size_t count
)
{
	// just for exposition,
	// try to write 200 bytes

	std::size_t const max_(
		std::min(
			count,
			static_cast<
				std::size_t
			>(
				200
			)
		)
	);

	for(
		std::size_t i = 0;
		i < max_;
		++i
	)
		*p++ = 'a';

	return max_;
}

}

int main()
{
	typedef fcppt::container::raw_vector<
		unsigned char
	> uc_raw_vector;

	// make space for 100 elements, but don't initialize them
	uc_raw_vector buffer(
		100
	);

	// resize the buffer to 150 elements, and also don't initialize them
	buffer.resize_uninitialized(
		150
	);

	std::size_t const read_count(
		read(
			buffer.data(),
			buffer.size()
		)
	);

	fcppt::io::cout()
		<< read_count
		<< FCPPT_TEXT(" bytes read.\n");
}

//]
