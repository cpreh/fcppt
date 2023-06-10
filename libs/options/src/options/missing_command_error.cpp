//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/options/missing_command_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_command_error::missing_command_error(std::vector<fcppt::string> &&_commands)
    : commands_{std::move(_commands)}
{
}

std::vector<fcppt::string> const &fcppt::options::missing_command_error::commands() const
{
  return this->commands_;
}
