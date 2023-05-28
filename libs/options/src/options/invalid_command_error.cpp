//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/options/invalid_command_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::invalid_command_error::invalid_command_error(fcppt::string &&_command)
    : command_{std::move(_command)}
{
}

fcppt::string const &fcppt::options::invalid_command_error::command() const
{
  return this->command_;
}
