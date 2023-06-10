//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive.hpp>
#include <fcppt/options/commands_usage.hpp>
#include <fcppt/options/sub_command_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

fcppt::options::commands_usage::commands_usage(
    fcppt::recursive<fcppt::options::usage> &&_options_usage,
    std::vector<fcppt::options::sub_command_usage> &&_sub_commands)
    : options_usage_{std::move(_options_usage)}, sub_commands_{std::move(_sub_commands)}
{
}

fcppt::recursive<fcppt::options::usage> const &
fcppt::options::commands_usage::options_usage() const
{
  return this->options_usage_;
}

std::vector<fcppt::options::sub_command_usage> const &
fcppt::options::commands_usage::sub_commands() const
{
  return this->sub_commands_;
}
