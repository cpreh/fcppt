//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/read.hpp>
#include <fcppt/io/write.hpp>
#include <fcppt/optional/maybe_void.hpp>
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

	// Read the written unsigned int back
	fcppt::optional::maybe_void(
		fcppt::io::read<
			unsigned
		>(
			stream,
			fcppt::endianness::format::big
		),
		[](
			unsigned const _result
		)
		{
			fcppt::io::cout()
				<< _result
				<< FCPPT_TEXT('\n');
		}
	);
//[io_endianness]
}
