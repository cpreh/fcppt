//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/filesystem/remove_extension.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"filesystem::remove_extension",
	"[filesystem]"
)
{
	std::filesystem::path const path1(
		std::filesystem::path(
			FCPPT_TEXT("foo")
		)
		/
		std::filesystem::path(
			FCPPT_TEXT("bar")
		)
	);

	CHECK(
		path1
		==
		fcppt::filesystem::remove_extension(
			path1
		)
	);

	std::filesystem::path const path2(
		path1
		/ FCPPT_TEXT("baz.txt")
	);

	CHECK(
		fcppt::filesystem::remove_extension(
			path2
		)
		==
		path1
		/
		FCPPT_TEXT("baz")
	);
}
