//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_INVALID_COMMAND_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_INVALID_COMMAND_ERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/invalid_command_error_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class invalid_command_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit invalid_command_error(fcppt::string &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string const &command() const;

  [[nodiscard]] bool operator==(invalid_command_error const &) const = default;
private:
  fcppt::string command_;
};

}

#endif
