//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_STATE_WITH_VALUE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_STATE_WITH_VALUE_IMPL_HPP_INCLUDED

#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T>
fcppt::options::state_with_value<T>::state_with_value(fcppt::options::state &&_state, T &&_value)
    : state_{std::move(_state)}, value_{std::move(_value)}
{
}

template <typename T>
fcppt::options::state &fcppt::options::state_with_value<T>::state()
{
  return this->state_;
}

template <typename T>
fcppt::options::state const &fcppt::options::state_with_value<T>::state() const
{
  return this->state_;
}

template <typename T>
T &fcppt::options::state_with_value<T>::value()
{
  return this->value_;
}

template <typename T>
T const &fcppt::options::state_with_value<T>::value() const
{
  return this->value_;
}

#endif
