//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_USE_OPTION_SUCCESS_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_USE_OPTION_SUCCESS_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/options/detail/use_option_success_fwd.hpp>

namespace fcppt::options::detail
{
class use_option_success
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL use_option_success(fcppt::options::name &&, fcppt::string &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::name const &name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string const &value() const;
private:
  fcppt::options::name name_;

  fcppt::string value_;
};
}

#endif
