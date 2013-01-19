//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <ostream>
#include <vector>
#include <fcppt/config/external_end.hpp>


int
main()
{
{
//! [raw_vector]
fcppt::container::raw_vector<int> raw_chars(
	1024);

// This is undefined, since raw_chars is not initialized.
std::cout << raw_chars[0];

std::ifstream file("test_file");
// Note here that raw_vector has a ::data member (unlike C++03's
// std::vector)
file.read(
	reinterpret_cast<char *>(
		raw_chars.data()),
	1024 *
	static_cast<
		std::streamsize
	>(
		sizeof(int)));
//! [raw_vector]
}
}
