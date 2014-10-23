//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/time/sleep_duration.hpp>


namespace fcppt
{
namespace time
{

/**
\brief Tries to sleep for a given duration

\ingroup fcppttime

Tries to sleep for \a duration.

\param duration The duration to sleep for

\throw fcppt::time::sleep_interrupted if sleeping for the requested time was
not possible
*/
FCPPT_DETAIL_SYMBOL
void
sleep(
	fcppt::time::sleep_duration const &duration
);

}
}

#endif
