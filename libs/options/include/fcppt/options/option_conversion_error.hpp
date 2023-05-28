//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTION_CONVERSION_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_CONVERSION_ERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/options/option_conversion_error_fwd.hpp>
#include <fcppt/options/type_name.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class option_conversion_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  option_conversion_error(
      fcppt::string, fcppt::options::type_name &&, fcppt::options::name &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::string const &arg() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::type_name const &type_name() const;

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::name const &name() const;

  [[nodiscard]] bool operator==(option_conversion_error const &) const = default;

private:
  fcppt::string arg_;

  fcppt::options::type_name type_name_;

  fcppt::options::name name_;
};

}

#endif
