//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/missing_error_fwd.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt
{
namespace options
{
/**
\brief A string type representing a missing error.

\ingroup fcpptoptions

A missing error is an error that occurs if a required argument or option has
not been specified. Such an error makes #fcppt::options::optional
parsers return an empty optional.
*/
class missing_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  missing_error(fcppt::options::state &&, fcppt::string &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::state &state();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::state const &state() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string &error();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string const &error() const;

private:
  fcppt::options::state state_;

  fcppt::string error_;
};

}
}

#endif
