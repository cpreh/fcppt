//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fstream>
#include <ios>
#include <iostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
//! [buffer]
	typedef
	fcppt::container::buffer::object<
		int
	>
	buffer_type;

	buffer_type raw_chars{
		1024
	};

	std::ifstream file{
		"test_file",
		std::ios_base::binary
	};

	if(
		file.read(
			// Hand the beginning of the write area to the read function.
			fcppt::cast::to_char_ptr<
				char *
			>(
				raw_chars.write_data()
			),
			fcppt::cast::size<
				std::streamsize
			>(
				fcppt::cast::to_signed(
					raw_chars.write_size()
					*
					sizeof(int)
				)
			)
		)
	)
		// If reading succeeded, we have read gcount bytes and therefore
		// gcount / sizeof(int) integers.
		raw_chars.written(
			fcppt::cast::size<
				buffer_type::size_type
			>(
				fcppt::cast::to_unsigned(
					file.gcount()
				)
			)
			/
			sizeof(int)
		);

	std::cout
		<< "Integers read: ";

	for(
		int const value
		:
		raw_chars
	)
		std::cout
			<< value << ", ";

	std::cout
		<< '\n';
//! [buffer]
}
