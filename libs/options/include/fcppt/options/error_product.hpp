//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_ERROR_PRODUCT_HPP_INCLUDED
#define FCPPT_OPTIONS_ERROR_PRODUCT_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>
#include <fcppt/options/error_fwd.hpp>
#include <fcppt/options/error_product_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
class error_product
{
public:
  using base = fcppt::recursive<fcppt::options::error>;

  FCPPT_OPTIONS_DETAIL_SYMBOL error_product(base &&, base &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base const &left() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL base const &right() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL bool operator==(error_product const &) const;
private:
  base left_;

  base right_;
};

}

#endif
