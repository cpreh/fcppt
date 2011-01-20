//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/is_executable.hpp>
#include <fcppt/filesystem/config.hpp>
#include <fcppt/config.hpp>
#if defined(FCPPT_POSIX_PLATFORM)
#include <fcppt/filesystem/exception.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/text.hpp>
#include <string>
#include <unistd.h>
#include <cerrno>
#endif

bool
fcppt::filesystem::is_executable(
#if defined(FCPPT_POSIX_PLATFORM)
	path const &_path
#else
	path const &
#endif
)
{
#if defined(FCPPT_POSIX_PLATFORM)
	if(
		::access(
#ifndef FCPPT_USE_FILESYSTEM_V3
			to_std_string(
				_path.string()
			).c_str()
#else
			_path.string<
				std::string
			>().c_str()
#endif
			,
			X_OK
		) == 0
	)
		return true;
	
	if(
		errno == EACCES
	)
		return false;
	
	throw filesystem::exception(
		FCPPT_TEXT("Can't read permissions on \"")
#ifndef FCPPT_USE_FILESYSTEM_V3
		+ _path.string()
#else
		+ _path.string<fcppt::string>()
#endif
		+ FCPPT_TEXT("\" because \"")
		+ error::strerrno()
		+ FCPPT_TEXT('"')
	);

#elif defined(FCPPT_WINDOWS_PLATFORM)
	return true;
#else
#error "Don't know if a file is executable."
#endif
}
