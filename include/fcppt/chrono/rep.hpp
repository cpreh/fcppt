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


#ifndef FCPPT_CHRONO_REP_HPP_INCLUDED
#define FCPPT_CHRONO_REP_HPP_INCLUDED

#include <fcppt/config.h>
#ifdef FCPPT_HAVE_ATLEAST_UINT64
#include <boost/cstdint.hpp>
#else
#include <fcppt/preprocessor/warning.hpp>
#endif

namespace fcppt
{
namespace chrono
{

#ifdef FCPPT_HAVE_ATLEAST_UINT64
typedef boost::uint64_t rep;
#else
typedef unsigned long rep;
FCPPT_PP_WARNING("This platform does not provide a 64 bit integer type. time_points may overflow too quickly.")
#endif

}
}

#endif
