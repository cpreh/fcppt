//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/missing_option_argument_error.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_option_argument_error::missing_option_argument_error(
    fcppt::options::name &&_option)
    : option_{std::move(_option)}
{
}

fcppt::options::name const &fcppt::options::missing_option_argument_error::name() const
{
  return this->option_;
}

bool fcppt::options::missing_option_argument_error::operator==(missing_option_argument_error const &) const = default;
