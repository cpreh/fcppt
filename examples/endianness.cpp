//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/from_big_endian.hpp>
#include <fcppt/endianness/from_little_endian.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/is_big_endian.hpp>
#include <fcppt/endianness/is_little_endian.hpp>
#include <fcppt/endianness/to_big_endian.hpp>
#include <fcppt/endianness/to_little_endian.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


//[endianness
int main()
{
	std::cout << "This system is big endian: " << fcppt::endianness::is_big_endian() << "\n";
	std::cout << "This system is little endian: " << fcppt::endianness::is_little_endian() << "\n";

	int const ivariable = 108;
	int const iconverted = fcppt::endianness::to_little_endian(ivariable);

	long const lvariable = 1337;
	long const lconverted = fcppt::endianness::to_big_endian(lvariable);

	std::cout << "integer, before: " << ivariable << ", integer, after: " << iconverted << "\n";
	std::cout << "long, before: " << lvariable << ", long, after: " << lconverted << "\n";

	// Should output 108
	std::cout << fcppt::endianness::from_little_endian(iconverted) << "\n";
	// Should output 1337
	std::cout << fcppt::endianness::from_big_endian(lconverted) << "\n";

	// Should output 0 or 1, depending on your local endianness
	std::cout << static_cast<unsigned>(fcppt::endianness::host_format()) << "\n";
}
//]
