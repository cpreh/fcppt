//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/raw_vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fstream>
#include <ios>
#include <fcppt/config/external_end.hpp>


int
main()
{
//! [raw_vector]
	fcppt::container::raw_vector<
		int
	> raw_chars(
		1024
	);

	// This is undefined, since raw_chars is not initialized.
	//std::cout << raw_chars[0];

	std::ifstream file("test_file");

	// Note here that raw_vector has a ::data member (unlike C++03's
	// std::vector)

	file.read(
		fcppt::cast::to_char_ptr<
			char *
		>(
			raw_chars.data()
		),
		fcppt::literal<
			std::streamsize
		>(
			1024
		)
		*
		fcppt::cast::size<
			std::streamsize
		>(
			fcppt::cast::to_signed(
				sizeof(int)
			)
		)
	);
//! [raw_vector]
}
