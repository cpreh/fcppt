//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/create_directory_failed.hpp>
#include <fcppt/text.hpp>

fcppt::filesystem::create_directory_failed::create_directory_failed(
	path const &what
)
:
	exception(
		FCPPT_TEXT("Failed to create directory \"")
		+ what.string()
		+ FCPPT_TEXT('"')
	)
{}
