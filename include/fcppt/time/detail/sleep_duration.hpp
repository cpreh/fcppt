//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_DETAIL_SLEEP_DURATION_HPP_INCLUDED
#define FCPPT_TIME_DETAIL_SLEEP_DURATION_HPP_INCLUDED

#include <fcppt/config/platform.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{
namespace detail
{

#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
typedef boost::chrono::milliseconds sleep_duration;
#elif defined(FCPPT_CONFIG_POSIX_PLATFORM)
typedef boost::chrono::nanoseconds sleep_duration;
#else
#error "Don't know what the sleep duration should be!"
#endif

}
}
}

#endif
