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


#include <fcppt/time/sleep.hpp>
#include <fcppt/time/sleep_interrupted.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/config.h>
#if defined(FCPPT_WINDOWS_PLATFORM)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif defined(FCPPT_POSIX_PLATFORM)
#include <time.h>
#else
#error "Don't know what to include for sleep!"
#endif

void
fcppt::time::sleep(
	sleep_duration const &duration_
)
{
#if defined(FCPPT_WINDOWS_PLATFORM)
	if(
		SleepEx(
			duration_.count(),
			TRUE
		)
		!= 0
	)
		throw sleep_interrupted();
#elif defined(FCPPT_POSIX_PLATFORM)
	timespec const req =
	{
		duration_.count() / sleep_duration::period::den,
		duration_.count() % sleep_duration::period::den
	};

	timespec rem;
	
	if(
		nanosleep(
			&req,
			&rem
		)
		!= 0
	)
		throw sleep_interrupted();
#else
#error "Don't know which sleep to call!"
#endif
}
