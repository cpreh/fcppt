//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/config/platform.hpp>
#include <fcppt/time/exception.hpp>
#include <fcppt/time/gmtime.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <time.h> // NOLINT(hicpp-deprecated-headers,modernize-deprecated-headers)
#include <fcppt/config/external_end.hpp>

std::tm fcppt::time::gmtime(std::time_t const _time)
{
#if defined(FCPPT_CONFIG_POSIX_PLATFORM)
  std::tm result{};
  if (gmtime_r(&_time, &result) == nullptr)
  {
    throw fcppt::time::exception{FCPPT_TEXT("gmtime_r failed")};
  }
  return result;
#elif defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
  std::tm result{};
  if(gmtime_s(&result, &_time) != 0)
  {
    throw fcppt::time::exception{FCPPT_TEXT("gmtime_s failed")};
  }
  return result;
#else
#error "Implement me!"
#endif
}
