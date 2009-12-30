/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


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
	path const &path_
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
