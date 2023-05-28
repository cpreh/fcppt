//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/options/leftover_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::leftover_error::leftover_error(fcppt::args_vector &&_args) : args_{std::move(_args)}
{
}

fcppt::args_vector const &fcppt::options::leftover_error::args() const
{
  return this->args_;
}
