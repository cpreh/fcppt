//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTION_NAME_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_NAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/option_name_fwd.hpp> // IWYU pragma: keep
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <compare>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief An option name that may be for a short or long option.

\ingroup fcpptoptions
*/
class option_name
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  option_name(fcppt::string &&, fcppt::options::is_short);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string const &name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::is_short is_short() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL std::strong_ordering operator<=>(option_name const &) const;
private:
  fcppt::string name_;

  fcppt::options::is_short is_short_;
};

}

#endif
