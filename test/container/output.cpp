//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::output",
	"[container]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const input{
		1,
		2
	};

	{
		std::ostringstream stream;

		stream
			<<
			fcppt::container::output(
				input
			);

		CHECK(
			stream.str()
			==
			std::string(
				"[1,2]"
			)
		);
	}

	{
		std::wostringstream stream;

		stream
			<<
			fcppt::container::output(
				input
			);

		CHECK(
			stream.str()
			==
			std::wstring(
				L"[1,2]"
			)
		);
	}
}
