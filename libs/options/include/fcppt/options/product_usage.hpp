//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PRODUCT_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_USAGE_HPP_INCLUDED

#include <fcppt/recursive.hpp>
#include <fcppt/recursive_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/product_usage_fwd.hpp> // IWYU pragma: keep
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
  FCPPT_OPTIONS_DETAIL_SYMBOL product_usage(fcppt::options::usage &&, fcppt::options::usage &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::usage const &left() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::usage const &right() const;

  [[nodiscard]] bool operator==(product_usage const &) const = default;
private:
  using base = fcppt::recursive<fcppt::options::usage>;

  base left_;

  base right_;
};

}

#endif
