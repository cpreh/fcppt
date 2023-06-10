//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_SWITCH_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SWITCH_DECL_HPP_INCLUDED

#include <fcppt/options/flag_impl.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text_fwd.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/switch_fwd.hpp>
#include <fcppt/options/usage_fwd.hpp>

namespace fcppt::options
{
/**
\brief A switch parser.

\ingroup fcpptoptions

A switch parser is similar to #fcppt::options::flag, but its value
type is fixed to <code>bool</code>, where its active value is <code>true</code>
and its inactive value is <code>false</code>.
*/
template <typename Label>
class switch_
{
  using impl = fcppt::options::flag<Label, bool>;

public:
  /**
  \brief Constructs a switch parser.

  \param short_name An optional short name ("-f") this parser will match.

  \param long_name The long name ("--flag") this parser will match.

  \param help_text Optional help text for this flag.
  */
  switch_(
      fcppt::options::optional_short_name &&short_name,
      fcppt::options::long_name &&long_name,
      fcppt::options::optional_help_text &&help_text);

  using result_type = typename impl::result_type;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const;

  [[nodiscard]] fcppt::options::option_name_set option_names() const;

  [[nodiscard]] fcppt::options::usage usage() const;

  [[nodiscard]] fcppt::options::optional_short_name const &short_name() const;

  [[nodiscard]] fcppt::options::long_name const &long_name() const;

  [[nodiscard]] fcppt::options::optional_help_text const &help_text() const;
private:
  impl impl_;
};

}

#endif
