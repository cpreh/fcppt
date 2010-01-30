//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/system_clock.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/config.h>
#ifdef FCPPT_WINDOWS_PLATFORM
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif FCPPT_POSIX_PLATFORM
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/text.hpp>
#include <sys/time.h>
#else
#error "system_clock implementation missing"
#endif

fcppt::chrono::system_clock::time_point
fcppt::chrono::system_clock::now()
{
#ifdef FCPPT_WINDOWS_PLATFORM
	FILETIME ret;
	GetSystemTimeAsFileTime(
		&ret
	);

	ULARGE_INTEGER large_int;
	large_int.u.LowPart = ret.dwLowDateTime;
	large_int.u.HighPart = ret.dwHighDateTime;

	return time_point(
		duration(
			large_int.QuadPart
		)
	);
#elif FCPPT_POSIX_PLATFORM
	struct timeval tv;
	struct timezone tz;

	if(
		gettimeofday(
			&tv,
			&tz
		) != 0
	)
		throw clock_failure(
			FCPPT_TEXT("gettimeofday() failed")
		);

	return time_point(
		duration(
			tv.tv_sec * period::den + tv.tv_usec
		)
	);
#endif
}


std::time_t
fcppt::chrono::system_clock::to_time_t(
	time_point const &point_
)
{
	return point_.time_since_epoch().count() / duration::period::den;
}

fcppt::chrono::system_clock::time_point
fcppt::chrono::system_clock::from_time_t(
	std::time_t const tm_
)
{
	return time_point(
		duration(
			tm_ * duration::period::den
		)
	);
}
