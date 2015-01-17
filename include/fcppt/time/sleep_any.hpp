//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_ANY_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_ANY_HPP_INCLUDED

#include <fcppt/time/sleep.hpp>
#include <fcppt/time/sleep_duration.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{

/**
\brief Tries to sleep for a given duration

\ingroup fcppttime

Tries to sleep for \a _duration.

\param _duration The duration to sleep for

\tparam Duration Must be a duration type

\see fcppt::time::sleep
*/
template<
	typename Duration
>
void
sleep_any(
	Duration const &_duration
)
{
	fcppt::time::sleep(
		std::chrono::duration_cast<
			fcppt::time::sleep_duration
		>(
			_duration
		)
	);
}

}
}

#endif
