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


#ifndef FCPPT_LOG_MACROS_HPP_INCLUDED
#define FCPPT_LOG_MACROS_HPP_INCLUDED

#include <fcppt/log/level.hpp>

#define FCPPT_LOG_LEVEL_IF_ENABLED(stream, l, x)\
	if((stream).activated(l))\
		(stream).log(l, x);

#define FCPPT_LOG_DEBUG(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::debug, x)

#define FCPPT_LOG_INFO(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::info, x)

#define FCPPT_LOG_WARNING(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::warning, x)

#define FCPPT_LOG_ERROR(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::error, x)

#define FCPPT_LOG_FATAL(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::fatal, x)

#endif
