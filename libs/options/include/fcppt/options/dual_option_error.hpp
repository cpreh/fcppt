//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DUAL_OPTION_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_DUAL_OPTION_ERROR_HPP_INCLUDED

#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/dual_option_error_fwd.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class dual_option_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  dual_option_error(fcppt::options::short_name, fcppt::options::long_name);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::short_name const &short_name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::long_name const &long_name() const;

  [[nodiscard]] bool operator==(dual_option_error const &) const = default;
private:
  fcppt::options::short_name short_name_;

  fcppt::options::long_name long_name_;
};
}

#endif
