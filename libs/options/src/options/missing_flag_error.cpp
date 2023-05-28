//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/long_name.hpp>
#include <fcppt/options/missing_flag_error.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_flag_error::missing_flag_error(
    fcppt::options::optional_short_name _short_name,
    fcppt::options::long_name _long_name)
    : short_name_{std::move(_short_name)}, long_name_{std::move(_long_name)}
{
}

fcppt::options::optional_short_name const &fcppt::options::missing_flag_error::short_name() const
{
  return this->short_name_;
}

fcppt::options::long_name const &fcppt::options::missing_flag_error::long_name() const
{
  return this->long_name_;
}
