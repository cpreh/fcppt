//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_error::missing_error(fcppt::options::state &&_state, fcppt::string &&_error)
    : state_{std::move(_state)}, error_{std::move(_error)}
{
}

fcppt::options::state &fcppt::options::missing_error::state() { return this->state_; }

fcppt::options::state const &fcppt::options::missing_error::state() const { return this->state_; }

fcppt::string &fcppt::options::missing_error::error() { return this->error_; }

fcppt::string const &fcppt::options::missing_error::error() const { return this->error_; }
