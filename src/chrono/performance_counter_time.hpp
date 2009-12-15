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


#ifndef FCPPT_CHRONO_PERFORMANCE_COUNTER_TIME_HPP_INCLUDED
#define FCPPT_CHRONO_PERFORMANCE_COUNTER_TIME_HPP_INCLUDED

#include "query_performance_frequency.hpp"
#include <fcppt/windows/windows.hpp>
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/text.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename TimePoint
>
TimePoint const
performance_counter_time()
{
	LARGE_INTEGER ret;

	if(
		QueryPerformanceCounter(
			&ret
		)
	)
		throw clock_failure(
			FCPPT_TEXT("QueryPerformanceCounter() failed!")
		);

	typedef double float_type;

	return
		TimePoint(
			typename TimePoint::duration(
				static_cast<
					typename TimePoint::rep
				>
				(
					static_cast<
						float_type
					>(
						ret.QuadPart
					)
					/
					static_cast<
						float_type
					>(
						query_performance_frequency().QuadPart
					)
					*
					static_cast<
						float_type
					>(
						TimePoint::period::den
					)
				)
			)
		);
}

}
}

#endif
