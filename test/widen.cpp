//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/widen.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"widen",
	"[codecvt]"
)
{
	// shouldn't need any multi byte characters
	std::string const input{
		"foobar"
	};

	// test this multiple times
	// because there was a corruption issue
	fcppt::algorithm::repeat(
		3u,
		[
			&input
		]{
			std::wstring const output(
				fcppt::widen(
					input
				)
			);

			CHECK(
				output.size()
				==
				6u
			);
		}
	);
}
