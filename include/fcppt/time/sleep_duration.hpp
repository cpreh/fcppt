//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_DURATION_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_DURATION_HPP_INCLUDED

#include <fcppt/time/detail/sleep_duration.hpp>

namespace fcppt
{
namespace time
{

/// The internal sleep duration
/**
 * It defines a duration that is most appropriate for a given platform.
*/
typedef fcppt::time::detail::sleep_duration sleep_duration;

}
}

#endif
