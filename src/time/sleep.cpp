//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/time/sleep.hpp>
#include <fcppt/time/sleep_interrupted.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <fcppt/config/include_windows.hpp>
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
	time::sleep_duration const &_duration
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	if(
		::SleepEx(
			fcppt::truncation_check_cast<
				DWORD
			>(
				_duration.count()
			),
			TRUE
		)
		!= 0
	)
		throw time::sleep_interrupted();
#elif defined(FCPPT_CONFIG_POSIX_PLATFORM)
	timespec const req =
	{
		fcppt::truncation_check_cast<
			std::time_t
		>(
			_duration.count() / sleep_duration::period::den
		),
		fcppt::truncation_check_cast<
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
		throw time::sleep_interrupted();
#else
#error "Don't know which sleep to call!"
#endif
}
