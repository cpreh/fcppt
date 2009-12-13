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


#ifndef SGE_CHRONO_TIME_POINT_CAST_HPP_INCLUDED
#define SGE_CHRONO_TIME_POINT_CAST_HPP_INCLUDED

#include <sge/chrono/time_point_impl.hpp>
#include <sge/chrono/duration_cast.hpp>

namespace sge
{
namespace chrono
{

template<
	typename ToDuration,
	typename Clock,
	typename Duration
>
time_point<
	Clock,
	ToDuration
>
time_point_cast(
	time_point<
		Clock,
		Duration
	> const &t
)
{
	return time_point<
		Clock,
		ToDuration
	>(
		duration_cast<
			ToDuration
		>(
			t.time_since_epoch()
		)
	);
}

}
}

#endif
