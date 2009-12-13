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


#ifndef SGE_CHRONO_TIME_POINT_COMPARISON_HPP_INCLUDED
#define SGE_CHRONO_TIME_POINT_COMPARISON_HPP_INCLUDED

#include <sge/chrono/time_point_impl.hpp>

namespace sge
{
namespace chrono
{

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator ==(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		lhs.time_since_epoch()
		== rhs.time_since_epoch();
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator !=(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		!(lhs == rhs);
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator <(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		lhs.since_time_epoch()
		< rhs.since_time_epoch();
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator <=(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		!(rhs < lhs);
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator >(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		rhs < lhs;
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator >=(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		!(lhs < rhs);
}

}
}

#endif
