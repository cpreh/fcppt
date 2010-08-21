//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_IMPL_CREATE_DIRECTORY_FAILED_HPP_INCLUDED
#define FCPPT_FILESYSTEM_IMPL_CREATE_DIRECTORY_FAILED_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/string.hpp>

inline
fcppt::filesystem::create_directory_failed::create_directory_failed(
	path const &_what
)
:
	filesystem::exception(
		FCPPT_TEXT("Failed to create directory \"")
		+ _what.string<fcppt::string>()
		+ FCPPT_TEXT('"')
	)
{}

#endif
