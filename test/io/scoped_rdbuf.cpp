//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/char_type.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/io/scoped_rdbuf.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ios>
#include <sstream>
#include <streambuf>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"io::scoped_rdbuf",
	"[io]"
)
{
	fcppt::io::ostream &stream{
		fcppt::io::cout()
	};

	std::basic_streambuf<
		fcppt::char_type
	> &old_buffer{
		*stream.rdbuf()
	};

	std::basic_stringbuf<
		fcppt::char_type
	> buffer{}; // NOLINT(fuchsia-default-arguments-calls)

	{
		std::basic_ios<
			fcppt::char_type
		> &stream_base{
			stream
		};

		std::basic_streambuf<
			fcppt::char_type
		> &buffer_base{
			buffer
		};

		fcppt::io::scoped_rdbuf const scoped_buf{
			fcppt::make_ref(
				stream_base
			),
			fcppt::make_ref(
				buffer_base
			)
		};

		CHECK(
			stream_base.rdbuf()
			==
			&buffer_base
		);
	}

	CHECK(
		stream.rdbuf()
		==
		&old_buffer
	);
}
