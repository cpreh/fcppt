//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/config/platform.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/time/localtime.hpp>
#include <fcppt/config/external_begin.hpp>
#include <time.h> // NOLINT(hicpp-deprecated-headers,modernize-deprecated-headers)
#include <ctime>
#include <fcppt/config/external_end.hpp>

fcppt::optional::object<std::tm> fcppt::time::localtime(std::time_t const _time)
{
#ifdef FCPPT_CONFIG_POSIX_PLATFORM
  std::tm result{};
  return fcppt::optional::make_if(
      localtime_r(&_time, &result) != nullptr, [&result] { return result; });
#elifdef FCPPT_CONFIG_WINDOWS_PLATFORM
  std::tm result{};
  return fcppt::optional::make_if(localtime_s(&result, &_time) == 0, [&result] { return result; });
#else
#error "Implement me!"
#endif
}
