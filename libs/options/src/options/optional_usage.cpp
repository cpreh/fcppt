//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/optional_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::optional_usage::optional_usage(fcppt::options::usage &&_inner)
    : inner_{std::move(_inner)}
{
}

fcppt::options::usage const &fcppt::options::optional_usage::inner() const
{
  return this->inner_.get();
}
