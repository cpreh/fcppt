//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	switch(
		fcppt::endianness::host_format()
	)
	{
	case fcppt::endianness::format::big:
		std::cout << "This system is big endian\n";
		break;
	case fcppt::endianness::format::little:
		std::cout << "This system is little endian\n";
		break;
	}

	int const ivariable(
		108
	);

	// Converts from the host format to little endian
	int const iconverted(
		fcppt::endianness::convert(
			ivariable,
			fcppt::endianness::format::little
		)
	);

	std::cout
		<< "integer, before: "
		<< ivariable
		<< ", integer, after: "
		<< iconverted
		<< '\n';

	// Convert the value back to the host format
	// Should output 108
	std::cout
		<< fcppt::endianness::convert(
			iconverted,
			fcppt::endianness::format::little
		)
		<< '\n';
}
//]
