//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_PERFORMANCE_COUNTER_TIME_HPP_INCLUDED
#define FCPPT_CHRONO_PERFORMANCE_COUNTER_TIME_HPP_INCLUDED

#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/text.hpp>
#include "query_performance_frequency.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace fcppt
{
namespace chrono
{

namespace
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
		== 0
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
}

#endif
