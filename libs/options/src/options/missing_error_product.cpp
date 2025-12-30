//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/missing_error_product.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::missing_error_product::missing_error_product(
    fcppt::options::missing_error_variant &&_left, fcppt::options::missing_error_variant &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::missing_error_variant &fcppt::options::missing_error_product::left()
{
  return this->left_.get();
}

fcppt::options::missing_error_variant const &fcppt::options::missing_error_product::left() const
{
  return this->left_.get();
}

fcppt::options::missing_error_variant &fcppt::options::missing_error_product::right()
{
  return this->right_.get();
}

fcppt::options::missing_error_variant const &fcppt::options::missing_error_product::right() const
{
  return this->right_.get();
}

bool fcppt::options::missing_error_product::operator==(missing_error_product const &_other) const = default;
