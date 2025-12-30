//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_product.hpp>
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::error_product::error_product(
    fcppt::options::error &&_left, fcppt::options::error &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::error const &fcppt::options::error_product::left() const
{
  return this->left_.get();
}

fcppt::options::error const &fcppt::options::error_product::right() const
{
  return this->right_.get();
}

bool fcppt::options::error_product::operator==(error_product const &_other) const = default;
