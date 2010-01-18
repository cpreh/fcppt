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

#if defined(FCPPT_LITTLE_ENDIAN) && defined(FCPPT_BIG_ENDIAN)
#error "FCPPT_LITTLE_ENDIAN and FCPPT_BIG_ENDIAN defined!"
#endif

#if !(defined(FCPPT_LITTLE_ENDIAN) || defined(FCPPT_BIG_ENDIAN))
#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/function_once.hpp>

namespace
{

fcppt::endianness::format::type endianness_;

void
init()
{
	FCPPT_FUNCTION_ONCE	

	// if unsigned long and char are of the same size
	// endianness doesn't matter

	typedef unsigned long int_type;

	int_type const t = 1u;

	typedef std::tr1::array<
		unsigned char,
		sizeof(int_type)
	> array_type;

	array_type array;

	fcppt::algorithm::copy_n(
		reinterpret_cast<
			unsigned char const *
		>(
			&t
		),
		sizeof(int_type),
		array.data()
	);

	endianness_ =
		array[0] == t
		?
			fcppt::endianness::format::little
		:
			fcppt::endianness::format::big;
}

}
#endif

fcppt::endianness::format::type
fcppt::endianness::host_format()
{
#if   defined(FCPPT_LITTLE_ENDIAN)
	return format::little;
#elif defined(FCPPT_BIG_ENDIAN)
	return format::big;
#else
	init();

	return endianness_;
#endif
}
