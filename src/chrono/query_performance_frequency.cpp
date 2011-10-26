//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include "query_performance_frequency.hpp"
#include <fcppt/config/include_windows.hpp>
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/text.hpp>

LARGE_INTEGER
fcppt::chrono::query_performance_frequency()
{
	LARGE_INTEGER frequency;

	if(
		::QueryPerformanceFrequency(
			&frequency
		)
		== 0
	)
		throw fcppt::chrono::clock_failure(
			FCPPT_TEXT("QueryPerformanceFrequency() failed!")
		);

	return frequency;
}

#endif
