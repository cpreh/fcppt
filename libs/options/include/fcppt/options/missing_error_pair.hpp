//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_ERROR_PAIR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ERROR_PAIR_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>
#include <fcppt/options/missing_error_pair_fwd.hpp>
#include <fcppt/options/missing_error_variant_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
class missing_error_pair
{
public:
  using base = fcppt::recursive<fcppt::options::missing_error_variant>;

  FCPPT_OPTIONS_DETAIL_SYMBOL missing_error_pair(base &&, base &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base &left();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base const &left() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base &right();

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base const &right() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL bool operator==(missing_error_pair const &) const;
private:
  base left_;

  base right_;
};

}

#endif
