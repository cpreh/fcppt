//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/getenv.hpp>
#include <fcppt/optional_std_string.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

fcppt::optional_std_string fcppt::getenv(std::string_view const &_val)
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4996)
  char const *const ret{std::getenv(std::string{_val}.c_str())}; // NOLINT(concurrency-mt-unsafe)
FCPPT_PP_POP_WARNING

  return ret == nullptr ? fcppt::optional_std_string{}
                        : fcppt::optional_std_string{std::string(ret)};
}
