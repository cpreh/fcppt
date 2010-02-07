//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/is_executable.hpp>
#include <fcppt/config.h>
#if defined(FCPPT_POSIX_PLATFORM)
#include <fcppt/filesystem/exception.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/text.hpp>
#include <unistd.h>
#include <cerrno>
#endif

bool
fcppt::filesystem::is_executable(
#if defined(FCPPT_POSIX_PLATFORM)
	path const &path_
#else
	path const &
#endif
)
{
#if defined(FCPPT_POSIX_PLATFORM)
	if(
		::access(
			path_.string().c_str(),
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
		+ path_.string()
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
