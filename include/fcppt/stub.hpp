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


#ifndef FCPPT_STUB_HPP_INCLUDED
#define FCPPT_STUB_HPP_INCLUDED

#include <fcppt/log/headers.hpp>
#include <ostream>

#define FCPPT_STUB_FUNCTION\
FCPPT_LOG_WARNING(\
	fcppt::log::global(),\
	fcppt::log::_1\
		<< FCPPT_TEXT("stub in ")\
		<< __FILE__\
		<< FCPPT_TEXT(" at ")\
		<< __LINE__);

#endif
