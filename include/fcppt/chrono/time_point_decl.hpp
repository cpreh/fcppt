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


#ifndef SGE_CHRONO_TIME_POINT_DECL_HPP_INCLUDED
#define SGE_CHRONO_TIME_POINT_DECL_HPP_INCLUDED

#include <sge/chrono/time_point_fwd.hpp>
#include <sge/chrono/duration_decl.hpp>

namespace sge
{
namespace chrono
{

template<
	typename Clock,
	typename Duration
>
class time_point {
public:
	typedef Clock clock;
	typedef Duration duration;
	typedef typename duration::rep rep;
	typedef typename duration::period period;

	time_point();

	explicit time_point(
		duration const &
	);

	template<
		typename Duration2
	>
	time_point(
		time_point<
			clock,
			Duration2
		> const &
	);

	duration
	time_since_epoch() const;

	time_point &
	operator +=(
		duration const &
	);

	time_point &
	operator -=(
		duration const &
	);

	static time_point
	min();

	static time_point
	max();
private:
	duration d_;
};

}
}

#endif
