//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/config.hpp>
#include <fcppt/platform.hpp>
#if defined(FCPPT_WINDOWS_PLATFORM)
#include "performance_counter_time.hpp"
#elif defined(FCPPT_HAVE_CLOCK_GETTIME)
#include "clock_gettime_impl.hpp"
#include <time.h>
#elif defined(FCPPT_HAVE_MACH_TIME)
#include "mach_time_impl.hpp"
#else
#error "high_resolution_clock implementation missing"
#endif

fcppt::chrono::high_resolution_clock::time_point
fcppt::chrono::high_resolution_clock::now()
{
#if defined(FCPPT_WINDOWS_PLATFORM)
	return
		chrono::performance_counter_time<
			time_point
		>();
#elif defined(FCPPT_HAVE_CLOCK_GETTIME)
	return
		chrono::clock_gettime_impl<
			time_point
		>(
			CLOCK_REALTIME
		);
#elif defined(FCPPT_HAVE_MACH_TIME)
	return
		chrono::mach_time_impl<
			time_point
		>();
#endif
}
