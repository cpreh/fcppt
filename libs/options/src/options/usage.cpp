//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::usage::usage(fcppt::options::usage_variant &&_impl)
: impl_{std::move(_impl)}
{
}

fcppt::options::usage_variant const &fcppt::options::usage::get() const
{
  return this->impl_;
}

bool fcppt::options::usage::operator==(usage const &) const noexcept = default;
