//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PRODUCT_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_USAGE_HPP_INCLUDED

#include <fcppt/recursive.hpp>
#include <fcppt/recursive_comparison.hpp>
#include <fcppt/options/product_usage_fwd.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class product_usage
{
public:
  using base = fcppt::recursive<fcppt::options::usage>;

  FCPPT_OPTIONS_DETAIL_SYMBOL product_usage(base &&, base &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base const &left() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base const &right() const;

  [[nodiscard]] bool operator==(product_usage const &) const = default;
private:
  base left_;

  base right_;
};

}

#endif
