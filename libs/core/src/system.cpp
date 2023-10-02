//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/system.hpp>
#include <fcppt/config/platform.hpp>
#include <fcppt/optional/object_impl.hpp>
#if defined(FCPPT_CONFIG_POSIX_PLATFORM)
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/types.h> // NOLINT(misc-include-cleaner)
#include <sys/wait.h> // NOLINT(misc-include-cleaner)
#include <cstdlib>
#include <fcppt/config/external_end.hpp>
#elif defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <fcppt/const.hpp>
#include <fcppt/public_config.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

#endif

fcppt::optional::object<int> fcppt::system(fcppt::string const &_command)
{
#if defined(FCPPT_CONFIG_POSIX_PLATFORM)
  int const result{
      // NOLINTNEXTLINE(cert-env33-c,concurrency-mt-unsafe)
      ::system(fcppt::optional::to_exception(fcppt::to_std_string(_command), [&_command] {
                 return fcppt::exception{
                     FCPPT_TEXT("Failed to convert command \"") + _command +
                     FCPPT_TEXT("\" for fcppt::system!")};
               }).c_str())};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wcast-qual)
  return fcppt::optional::make_if(
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      WIFEXITED(result), // NOLINT(misc-include-cleaner)
      [result] {
        return
            // NOLINTNEXTLINE(hicpp-signed-bitwise)
            WEXITSTATUS(result); // NOLINT(misc-include-cleaner)
      });
FCPPT_PP_POP_WARNING
#elif defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
  int const result
  {
#if defined(FCPPT_NARROW_STRING)
    ::system(
#else
    _wsystem(
#endif
        _command.c_str())
  };

  return fcppt::optional::make_if(result != -1, fcppt::const_(result));
#else
#error "Implement me!"
#endif
}
