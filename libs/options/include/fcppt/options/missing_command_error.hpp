//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_COMMAND_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_COMMAND_ERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/missing_command_error_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class missing_command_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit missing_command_error(std::vector<fcppt::string> &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL std::vector<fcppt::string> const &commands() const;

  [[nodiscard]] bool operator==(missing_command_error const &) const = default;
private:
  std::vector<fcppt::string> commands_;
};

}

#endif
