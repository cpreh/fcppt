//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/error.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::error::error(fcppt::options::error_variant &&_impl)
: impl_{std::move(_impl)}
{
}

fcppt::options::error_variant const &fcppt::options::error::get() const
{
  return this->impl_;
}

bool fcppt::options::operator==(
    fcppt::options::error const &_left, fcppt::options::error const &_right) noexcept
{
  return _left.get() == _right.get();
}
