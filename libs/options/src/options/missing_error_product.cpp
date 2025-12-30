//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive_comparison.hpp>
#include <fcppt/options/missing_error_product.hpp>
#include <fcppt/options/missing_error_variant.hpp> // IWYU pragma: keep
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_error_product::missing_error_product(base &&_left, base &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::missing_error_product::base &fcppt::options::missing_error_product::left()
{
  return this->left_;
}

fcppt::options::missing_error_product::base const &fcppt::options::missing_error_product::left() const
{
  return this->left_;
}

fcppt::options::missing_error_product::base &fcppt::options::missing_error_product::right()
{
  return this->right_;
}

fcppt::options::missing_error_product::base const &fcppt::options::missing_error_product::right() const
{
  return this->right_;
}

bool fcppt::options::missing_error_product::operator==(missing_error_product const &_other) const
{
  return this->left_ == _other.left_ && this->right_ == _other.right_;
}
