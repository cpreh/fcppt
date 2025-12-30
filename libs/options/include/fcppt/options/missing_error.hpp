//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ERROR_HPP_INCLUDED

#include <fcppt/options/missing_error_fwd.hpp> // IWYU pragma: keep
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\brief Occurs if an argument/flag/option is missing.

\ingroup fcpptoptions

A missing error is an error that occurs if a required argument, flag or option has
not been specified. Such an error makes #fcppt::options::optional
parsers return an empty optional.

Usually, a single parse step is destructive, since parsers extract arguments, flags or options from the state.
However, in case a missing error occurs, the state is left unchanged, and it is therefore preserved as part of the missing_error.
This makes it possible, for example, for product parsers to continue parsing and potentially accumulate more errors.
*/
class missing_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  missing_error(fcppt::options::state &&, fcppt::options::missing_error_variant &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::state &state();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::state const &state() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::missing_error_variant &error();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::missing_error_variant const &
  error() const;

private:
  fcppt::options::state state_;

  fcppt::options::missing_error_variant error_;
};

}

#endif
