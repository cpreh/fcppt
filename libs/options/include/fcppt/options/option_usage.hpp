//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTION_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_USAGE_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_usage_fwd.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/type_name.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class option_usage
{
public:
  FCPPT_DECLARE_STRONG_TYPEDEF(fcppt::optional::object<fcppt::string>, default_value_type);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  option_usage(
      default_value_type &&,
      fcppt::options::long_name,
      fcppt::options::optional_short_name,
      fcppt::options::type_name &&,
      fcppt::options::optional_help_text);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::optional::object<fcppt::string> const &
  default_value() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::long_name const &long_name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::optional_short_name const &
  short_name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::type_name const &type() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::optional_help_text const &
  help_text() const;

  [[nodiscard]] bool operator==(option_usage const &) const = default;
private:
  fcppt::optional::object<fcppt::string> default_value_;

  fcppt::options::long_name long_name_;

  fcppt::options::optional_short_name short_name_;

  fcppt::options::type_name type_;

  fcppt::options::optional_help_text help_text_;
};

}

#endif
