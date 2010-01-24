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


#ifndef FCPPT_CHRONO_TIME_POINT_DECL_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_DECL_HPP_INCLUDED

#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/duration_decl.hpp>

namespace fcppt
{
namespace chrono
{

/// Represents a given point in time, measured by a Clock's now() function.
/**
 * Clock is the type of the clock from where the time_point was obtained.
 * Duration is the associated duration.
 * durations can be added to or subtracted from time_points to obtain a
 * time_point further in the future or in the past.
 * Two time_points can be subtracted to get the difference between them (as a duration).
 * time_since_epoch() directly converts the time_point into a duration, using
 * the clocks beginning time as a second time_point.
*/
template<
	typename Clock,
	typename Duration
>
class time_point
{
public:
	typedef Clock clock;
	typedef Duration duration;
	typedef typename duration::rep rep;
	typedef typename duration::period period;

	time_point();

	/// Constructs a time_point from a duration.
	/** This duration is interpreted as if it were obtained from time_since_epoch().
	*/
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

	/// duration from the beginning of the Clock to this time_point
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
