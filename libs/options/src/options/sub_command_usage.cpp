//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/sub_command_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::sub_command_usage::sub_command_usage(
    fcppt::string _name,
    fcppt::recursive<fcppt::options::usage> &&_inner,
    fcppt::options::optional_help_text _help_text)
    : name_{std::move(_name)}, inner_{std::move(_inner)}, help_text_{std::move(_help_text)}
{
}

fcppt::string const &fcppt::options::sub_command_usage::name() const { return this->name_; }

fcppt::recursive<fcppt::options::usage> const &fcppt::options::sub_command_usage::inner() const
{
  return this->inner_;
}

fcppt::options::optional_help_text const &fcppt::options::sub_command_usage::help_text() const
{
  return this->help_text_;
}
