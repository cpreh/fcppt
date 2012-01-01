//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/system_clock.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/config/platform.hpp>
#include <fcppt/truncation_check_cast.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <fcppt/config/include_windows.hpp>
#elif defined(FCPPT_CONFIG_POSIX_PLATFORM)
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/time.h>
#include <fcppt/config/external_end.hpp>
#else
#error "system_clock implementation missing"
#endif

fcppt::chrono::system_clock::time_point
fcppt::chrono::system_clock::now()
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	FILETIME ret;

	::GetSystemTimeAsFileTime(
		&ret
	);

	ULARGE_INTEGER large_int;
	large_int.u.LowPart = ret.dwLowDateTime;
	large_int.u.HighPart = ret.dwHighDateTime;

	return
		time_point(
			duration(
				fcppt::truncation_check_cast<
					duration::rep
				>(
					large_int.QuadPart
				)
			)
		);
#elif defined(FCPPT_CONFIG_POSIX_PLATFORM)
	struct timeval tv;
	struct timezone tz;

	if(
		::gettimeofday(
			&tv,
			&tz
		) != 0
	)
		throw chrono::clock_failure(
			FCPPT_TEXT("gettimeofday() failed")
		);

	return
		time_point(
			duration(
				tv.tv_sec
				* 1000000L
				+
				tv.tv_usec
			)
		);
#else
#error "Implement me!"
#endif
}


std::time_t
fcppt::chrono::system_clock::to_time_t(
	time_point const &_point
)
{
	return
		fcppt::truncation_check_cast<
			std::time_t
		>(
			_point.time_since_epoch().count()
			/ duration::period::den
		);
}

fcppt::chrono::system_clock::time_point
fcppt::chrono::system_clock::from_time_t(
	std::time_t const _tm
)
{
	return
		time_point(
			duration(
				fcppt::truncation_check_cast<
					duration::rep
				>(
					_tm * duration::period::den
				)
			)
		);
}
