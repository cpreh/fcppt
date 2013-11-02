//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/read.hpp>
#include <fcppt/io/write.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


int
main()
{
//[io_endianness]
	std::stringstream stream;

	// Write 42u into the stream, using big endianness
	fcppt::io::write(
		stream,
		42u,
		fcppt::endianness::format::big
	);

	typedef fcppt::optional<
		unsigned
	> optional_unsigned;

	// Read the written unsigned int back
	optional_unsigned const result(
		fcppt::io::read<
			unsigned
		>(
			stream,
			fcppt::endianness::format::big
		)
	);

	// Should output 42
	if(
		result
	)
		fcppt::io::cout()
			<< *result
			<< FCPPT_TEXT('\n');
//[io_endianness]
}
