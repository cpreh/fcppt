//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive_comparison.hpp>
#include <fcppt/options/missing_error_sum.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_error_sum::missing_error_sum(
    fcppt::options::missing_error_variant &&_left, fcppt::options::missing_error_variant &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::missing_error_variant &fcppt::options::missing_error_sum::left()
{
  return this->left_.get();
}

fcppt::options::missing_error_variant const &fcppt::options::missing_error_sum::left() const
{
  return this->left_.get();
}

fcppt::options::missing_error_variant &fcppt::options::missing_error_sum::right()
{
  return this->right_.get();
}

fcppt::options::missing_error_variant const &fcppt::options::missing_error_sum::right() const
{
  return this->right_.get();
}

bool fcppt::options::missing_error_sum::operator==(missing_error_sum const &_other) const = default;
