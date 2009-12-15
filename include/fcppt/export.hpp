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


#ifndef FCPPT_EXPORT_HPP_INCLUDED
#define FCPPT_EXPORT_HPP_INCLUDED

#include <fcppt/config.h>

#if defined(_MSC_VER)
#	define FCPPT_EXPORT_SYMBOL __declspec(dllexport)
#	define FCPPT_IMPORT_SYMBOL __declspec(dllimport)

#	ifdef fcpptcore_EXPORTS
#		define FCPPT_SYMBOL FCPPT_EXPORT_SYMBOL
#	else
#		define FCPPT_SYMBOL FCPPT_IMPORT_SYMBOL
#	endif

#	define FCPPT_CLASS_SYMBOL
#elif defined(__GNUC__) && defined(FCPPT_HAVE_GCC_VISIBILITY)
#	define FCPPT_SYMBOL __attribute__ ((visibility("default")))
#	define FCPPT_EXPORT_SYMBOL FCPPT_SYMBOL
#	define FCPPT_IMPORT_SYMBOL
#	define FCPPT_CLASS_SYMBOL FCPPT_SYMBOL
#else
#	define FCPPT_SYMBOL
#	define FCPPT_EXPORT_SYMBOL
#	define FCPPT_IMPORT_SYMBOL
#	define FCPPT_CLASS_SYMBOL
#endif


#endif // FCPPT_EXPORT_HPP_INCLUDED
