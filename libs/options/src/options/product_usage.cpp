//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/product_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::product_usage::product_usage(
    fcppt::options::usage &&_left, fcppt::options::usage &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::usage const &fcppt::options::product_usage::left() const
{
  return this->left_.get();
}

fcppt::options::usage const &fcppt::options::product_usage::right() const
{
  return this->right_.get();
}
