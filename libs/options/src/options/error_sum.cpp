//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive_comparison.hpp>
#include <fcppt/options/error.hpp> // IWYU pragma: keep
#include <fcppt/options/error_sum.hpp>
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::error_sum::error_sum(base &&_left, base &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::error_sum::base const &fcppt::options::error_sum::left() const
{
  return this->left_;
}

fcppt::options::error_sum::base const &fcppt::options::error_sum::right() const
{
  return this->right_;
}

bool fcppt::options::error_sum::operator==(error_sum const &_other) const
{
  return this->left_ == _other.left_ && this->right_ == _other.right_;
}
