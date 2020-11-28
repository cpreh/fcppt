//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/getenv.hpp>
#include <fcppt/optional_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

fcppt::optional_std_string fcppt::getenv(std::string_view const &_val)
{
  char const *const ret{std::getenv(std::string{_val}.c_str())};

  return ret == nullptr ? fcppt::optional_std_string{}
                        : fcppt::optional_std_string{std::string(ret)};
}
