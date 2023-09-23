//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/recursive.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/options/product_usage.hpp>
#include <fcppt/options/usage.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::product_usage::product_usage(base &&_left, base &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::product_usage::base const &fcppt::options::product_usage::left() const
{
  return this->left_;
}

fcppt::options::product_usage::base const &fcppt::options::product_usage::right() const
{
  return this->right_;
}
