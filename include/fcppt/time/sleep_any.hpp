//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_ANY_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_ANY_HPP_INCLUDED

#include <fcppt/time/sleep.hpp>
#include <fcppt/time/sleep_duration.hpp>
#include <fcppt/chrono/duration_cast.hpp>
#include <fcppt/chrono/duration_impl.hpp>

namespace fcppt
{
namespace time
{

/// Sleep for a given duration
/**
 * \tparam Duration must be a chrono::duration
 * \see sleep
*/
template<
	typename Duration
>
void
sleep_any(
	Duration const &duration_
)
{
	sleep(
		chrono::duration_cast<
			sleep_duration
		>(
			duration_
		)
	);
}

}
}

#endif
