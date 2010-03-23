//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_DETAIL_SLEEP_DURATION_HPP_INCLUDED
#define FCPPT_TIME_DETAIL_SLEEP_DURATION_HPP_INCLUDED

#include <fcppt/config.hpp>
#if defined(FCPPT_WINDOWS_PLATFORM)
#include <fcppt/chrono/milliseconds.hpp>
#elif defined(FCPPT_POSIX_PLATFORM)
#include <fcppt/chrono/nanoseconds.hpp>
#else
#error "Don't know what to include for the sleep_duration!"
#endif

namespace fcppt
{
namespace time
{
namespace detail
{

#if defined(FCPPT_WINDOWS_PLATFORM)
typedef fcppt::chrono::milliseconds sleep_duration;
#elif defined(FCPPT_POSIX_PLATFORM)
typedef fcppt::chrono::nanoseconds sleep_duration;
#else
#error "Don't know what the sleep duration should be!"
#endif

}
}
}

#endif
