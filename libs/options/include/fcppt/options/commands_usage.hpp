//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_COMMANDS_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_COMMANDS_USAGE_HPP_INCLUDED

#include <fcppt/recursive.hpp>
#include <fcppt/recursive_comparison.hpp>
#include <fcppt/options/commands_usage_fwd.hpp>
#include <fcppt/options/sub_command_usage.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
class commands_usage
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  commands_usage(
      fcppt::recursive<fcppt::options::usage> &&,
      std::vector<fcppt::options::sub_command_usage> &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::recursive<fcppt::options::usage> const &
  options_usage() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL std::vector<fcppt::options::sub_command_usage> const &
  sub_commands() const;

  [[nodiscard]] bool operator==(commands_usage const &) const = default;
private:
  fcppt::recursive<fcppt::options::usage> options_usage_;

  std::vector<fcppt::options::sub_command_usage> sub_commands_;
};

}

#endif
