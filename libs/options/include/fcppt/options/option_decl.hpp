//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTION_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_DECL_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/default_value.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/object_fwd.hpp>

namespace fcppt::options
{
/**
\brief An option parser

\ingroup fcpptoptions

An option parser matches the next command-line parameter that <em>follows after</em>
its short name ("-o") or its long name ("--option"), for example "--output log.txt".
If there is no such pair of command-line parameters, then the option will use its
<em>default value</em> if is has one. Otherwise, it will fail.
The result of an option is a record that has a single element with label \a Label and
type \a Type. In case reading the value into \a Type fails, the parser also fails.

\tparam Label An #fcppt::record::label.

\tparam Type The type of the flag's value.
*/
template <typename Label, typename Type>
class option
{
public:
  using optional_default_value = fcppt::options::default_value<fcppt::optional::object<Type>>;

  /**
  \brief Constructs an option parser.

  \param short_name An optional short name ("-o") this parser will match.

  \param long_name The long name ("--option") this parser will match.

  \param default_value An optional default value for this parser.

  \param help_text Optional help text for this flag.
  */
  option(
      fcppt::options::optional_short_name &&short_name,
      fcppt::options::long_name &&long_name,
      optional_default_value &&default_value,
      fcppt::options::optional_help_text &&help_text);

  using element_type = fcppt::record::element<Label, Type>;

  using result_type = fcppt::record::object<element_type>;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const;

  [[nodiscard]] fcppt::options::option_name_set option_names() const;

  [[nodiscard]] fcppt::options::usage usage() const;

private:
  fcppt::options::optional_short_name short_name_;

  fcppt::options::long_name long_name_;

  optional_default_value default_value_;

  fcppt::options::optional_help_text help_text_;
};

}

#endif
