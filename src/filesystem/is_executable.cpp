//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/is_executable.hpp>
#include <fcppt/platform.hpp>
#if defined(FCPPT_POSIX_PLATFORM)
#include <fcppt/filesystem/exception.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <unistd.h>
#include <cerrno>
#include <fcppt/config/external_end.hpp>
#endif

bool
fcppt::filesystem::is_executable(
#if defined(FCPPT_POSIX_PLATFORM)
	filesystem::path const &_path
#else
	filesystem::path const &
#endif
)
{
#if defined(FCPPT_POSIX_PLATFORM)
	if(
		::access(
			_path.string<
				std::string
			>().c_str()
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
		+
		fcppt::filesystem::path_to_string(
			_path
		)
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
