//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_ANY_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_ANY_HPP_INCLUDED

#include <fcppt/time/sleep.hpp>
#include <fcppt/time/sleep_duration.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <fcppt/config/external_end.hpp>


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
	Duration const &_duration
)
{
	fcppt::time::sleep(
		boost::chrono::duration_cast<
			fcppt::time::sleep_duration
		>(
			_duration
		)
	);
}

}
}

#endif
