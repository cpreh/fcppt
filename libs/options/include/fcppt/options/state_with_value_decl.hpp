//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_STATE_WITH_VALUE_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_STATE_WITH_VALUE_DECL_HPP_INCLUDED

#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value_fwd.hpp>

namespace fcppt
{
namespace options
{
/**
\brief A parse state together with a value.

\ingroup fcpptoptions
*/
template <typename T>
class state_with_value
{
public:
  state_with_value(fcppt::options::state &&, T &&);

  [[nodiscard]] fcppt::options::state &state();

  [[nodiscard]] fcppt::options::state const &state() const;

  [[nodiscard]] T &value();

  [[nodiscard]] T const &value() const;

private:
  fcppt::options::state state_;

  T value_;
};

}
}

#endif
