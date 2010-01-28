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


#ifndef FCPPT_TIME_SLEEP_DURATION_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_DURATION_HPP_INCLUDED

#include <fcppt/config.h>
#if defined(FCPPT_WINDOWS_PLATFORM)
#include <fcppt/chrono/milliseconds.hpp>
#elif defined(FCPPT_POSIX_PLATFORM)
#include <fcppt/chrono/nanoseconds.hpp>
#else
#error "Don't know what to include for the sleep_duration!"
#endif

namespace fcppt
{
namespace time
{

#if defined(FCPPT_WINDOWS_PLATFORM)
typedef fcppt::chrono::milliseconds sleep_duration;
#elif defined(FCPPT_POSIX_PLATFORM)
typedef fcppt::chrono::nanoseconds sleep_duration;
#else
#error "Don't know what the sleep duration should be!"
#endif

}
}

#endif
