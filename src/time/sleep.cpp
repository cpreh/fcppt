//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/time/sleep.hpp>
#include <fcppt/time/sleep_interrupted.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <fcppt/src/include_windows.hpp>
#elif defined(FCPPT_CONFIG_POSIX_PLATFORM)
#include <fcppt/config/external_begin.hpp>
#include <time.h>
#include <ctime>
#include <fcppt/config/external_end.hpp>
#else
#error "Don't know what to include for sleep!"
#endif

void
fcppt::time::sleep(
	fcppt::time::sleep_duration const &_duration
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	if(
		::SleepEx(
			fcppt::cast::truncation_check<
				DWORD
			>(
				_duration.count()
			),
			TRUE
		)
		!= 0
	)
		throw fcppt::time::sleep_interrupted();
#elif defined(FCPPT_CONFIG_POSIX_PLATFORM)
	timespec const req =
	{
		fcppt::cast::truncation_check<
			std::time_t
		>(
			_duration.count() / sleep_duration::period::den
		),
		fcppt::cast::truncation_check<
			long
		>(
			_duration.count() % sleep_duration::period::den
		)
	};

	timespec rem;

	if(
		::nanosleep(
			&req,
			&rem
		)
		!= 0
	)
		throw fcppt::time::sleep_interrupted();
#else
#error "Don't know which sleep to call!"
#endif
}
