//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/missing_argument_error.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_argument_error::missing_argument_error(fcppt::options::long_name _long_name)
    : long_name_{std::move(_long_name)}
{
}

fcppt::options::long_name const &fcppt::options::missing_argument_error::long_name() const
{
  return this->long_name_;
}
