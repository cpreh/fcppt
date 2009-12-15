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


#include <fcppt/endianness/host_format.hpp>
#include <fcppt/config.h>

#if defined(FCPPT_LITTLE_ENDIAN) && defined(FCCPT_BIG_ENDIAN)
#error "FCPPT_LITTLE_ENDIAN and FCCPT_BIG_ENDIAN defined!"
#endif

fcppt::endianness::format::type
fcppt::endianness::host_format()
{
#if   defined(FCPPT_LITTLE_ENDIAN)
	return format::little;
#elif defined(FCPPT_BIG_ENDIAN)
	return format::big;
#else
	// if unsigned long and char are of the same size
	// endianness doesn't matter
	typedef unsigned long type;
	union {
		type t;
		unsigned char c[sizeof(type)];
	} u;
	u.t = 1u;

	return u.c[0] == u.t
		? format::little
		: format::big;
#endif
}
