//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_UNIT_SWITCH_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_SWITCH_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/switch_impl.hpp>
#include <fcppt/options/unit_switch_fwd.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/object_fwd.hpp>

namespace fcppt
{
namespace options
{
/**
\brief A required switch.

\ingroup fcpptoptions

This parser is similar to #fcppt::options::switch_ but it
requires its switch to be specified.
*/
template <typename Label>
class unit_switch
{
  using impl = fcppt::options::switch_<Label>;

public:
  /**
  \brief Constructs a switch parser.

  \param short_name An optional short name ("-f") this parser will match.

  \param long_name The long name ("--flag") this parser will match.
  */
  unit_switch(
      fcppt::options::optional_short_name &&short_name, fcppt::options::long_name &&long_name);

  using result_type = fcppt::record::object<fcppt::record::element<Label, fcppt::unit>>;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const;

  [[nodiscard]] fcppt::options::option_name_set option_names() const;

  [[nodiscard]] fcppt::string usage() const;

  [[nodiscard]] fcppt::options::optional_short_name const &short_name() const;

  [[nodiscard]] fcppt::options::long_name const &long_name() const;

private:
  impl impl_;
};

}
}

#endif
