//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_SUB_COMMAND_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_SUB_COMMAND_USAGE_HPP_INCLUDED

#include <fcppt/recursive.hpp>
#include <fcppt/recursive_comparison.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/sub_command_usage_fwd.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
class sub_command_usage
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  sub_command_usage(
      fcppt::string,
      fcppt::recursive<fcppt::options::usage> &&,
      fcppt::options::optional_help_text);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string const &name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::recursive<fcppt::options::usage> const &
  inner() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::optional_help_text const &
  help_text() const;

  [[nodiscard]] bool operator==(sub_command_usage const &) const = default;
private:
  fcppt::string name_;

  fcppt::recursive<fcppt::options::usage> inner_;

  fcppt::options::optional_help_text help_text_;
};

}

#endif
