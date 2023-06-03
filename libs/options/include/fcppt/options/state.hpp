//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_STATE_HPP_INCLUDED
#define FCPPT_OPTIONS_STATE_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\brief A parse state.

\ingroup fcpptoptions

A state contains a list of unconsumed arguments.
*/
class state
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  explicit state(fcppt::args_vector &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL bool empty() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::args_vector &args();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::args_vector const &args() const;
private:
  fcppt::args_vector args_;
};

}

#endif
