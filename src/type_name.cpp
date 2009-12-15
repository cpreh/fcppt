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


#include <fcppt/type_name.hpp>
#include <fcppt/iconv.hpp>
#ifdef FCPPT_HAS_GNU_DEMANGLE
#include <cxxabi.h>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/c_deleter.hpp>
#endif

fcppt::string const
fcppt::type_name(
	fcppt::type_info const &ti)
{
#ifdef FCPPT_HAS_GNU_DEMANGLE
	int status;

	scoped_ptr<
		char,
		c_deleter
	> name(
		abi::__cxa_demangle(
			ti.get().name(),
			0,
			0,
			&status
		)
	);

	// demangling failed?
	return status
		? iconv(ti.get().name())
		: iconv(name.get());
#else
	return iconv(
		ti.get().name()
	);
#endif
}
