//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/config.h>
#ifdef FCPPT_WINDOWS_PLATFORM
#include "query_performance_frequency.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/function_once.hpp>
#include <fcppt/text.hpp>

namespace
{

LARGE_INTEGER frequency;

void
init()
{
	FCPPT_FUNCTION_ONCE;

	if(
		QueryPerformanceFrequency(
			&frequency
		)
		== 0
	)
		throw fcppt::chrono::clock_failure(
			FCPPT_TEXT("QueryPerformanceFrequency() failed!")
		);

}

}

LARGE_INTEGER
fcppt::chrono::query_performance_frequency()
{
	init();

	return frequency;
}

#endif
