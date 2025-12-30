//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/sum_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::sum_usage::sum_usage(fcppt::options::usage &&_left, fcppt::options::usage &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

fcppt::options::usage const &fcppt::options::sum_usage::left() const
{
  return this->left_.get();
}

fcppt::options::usage const &fcppt::options::sum_usage::right() const
{
  return this->right_.get();
}
