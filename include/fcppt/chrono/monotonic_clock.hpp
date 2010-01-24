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


#ifndef FCPPT_CHRONO_MONOTONIC_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_MONOTONIC_CLOCK_HPP_INCLUDED

#include <fcppt/chrono/monotonic_clock_fwd.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/ratio.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace chrono
{

/// Provides a monotonic clock.
/** For two calls to now() in sequence, t1 = now(); t2 = now();,
 * t2 will always be greater than t1.
*/
class monotonic_clock
{
public:
	typedef chrono::rep rep;

	typedef nano period;

	typedef fcppt::chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		monotonic_clock
	> time_point;

	static bool const is_monotonic = true;

	FCPPT_SYMBOL
	static time_point
	now();
};

}
}

#endif
