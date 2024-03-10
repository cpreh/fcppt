//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_COMMANDS_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_COMMANDS_DECL_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/options/commands_fwd.hpp> // IWYU pragma: keep
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/all_disjoint.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A parser for multiple sub commands.

\ingroup fcpptoptions

A commands parser parses multiple sub commands.  Each sub command consists of a
parser and a name, i.e. <code>(name_1, parser_1), ..., (name_n, parser_n)</code>.
The parser first searches for the first argument, ignoring all option names
from \a OptionsParser.  If none is found, the parser fails.  Otherwise, the
first argument is <code>arg</code>, which is then compared to
<code>name_1, ..., name_n</code>. If none of these is equal to <code>arg</code>, the parser
fails.  Otherwise, let <code>arg = name_i</code>, then the \a OptionsParser
is used to parse everything up to the first argument, and <code>parser_i</code>
is used to parse everything after.

\warning Be careful not to include anything other than options or flags
in \a OptionsParser, because otherwise this may lead to very confusing results.

\tparam OptionsParser A parser that should only parse options.
*/
template <typename OptionsParser, typename... SubCommands>
class commands
{
public:
  static_assert(sizeof...(SubCommands) >= 1U, "You must specify at least one subparser");

  static_assert(
      fcppt::record::all_disjoint<fcppt::mpl::list::map<
          fcppt::mpl::list::object<SubCommands...>,
          fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::options::result_of>, fcppt::mpl::arg<1>>>>::
          value,
      "All sub-command labels must be distinct");

  /**
  \brief Constructs a commands parser.

  \tparam OptionsParserArg A cv-ref to \a OptionsParser
  \tparam SubCommandsArgs Cv-refs to \a SubCommands
  */
  template <typename OptionsParserArg, typename... SubCommandsArgs>
  explicit commands(OptionsParserArg &&, SubCommandsArgs &&...)
    requires(std::conjunction_v<
             std::is_same<OptionsParser, std::remove_cvref_t<OptionsParserArg>>,
             std::is_same<SubCommands, std::remove_cvref_t<SubCommandsArgs>>...>);

  using variant_result = fcppt::variant::object<fcppt::options::result_of<SubCommands>...>;

  using result_type = fcppt::record::object<
      fcppt::record::
          element<fcppt::options::options_label, fcppt::options::result_of<OptionsParser>>,
      fcppt::record::element<fcppt::options::sub_command_label, variant_result>>;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const;

  [[nodiscard]] fcppt::options::option_name_set option_names() const;

  [[nodiscard]] fcppt::options::usage usage() const;

private:
  OptionsParser options_parser_;

  fcppt::tuple::object<SubCommands...> sub_commands_;
};

FCPPT_PP_POP_WARNING

}

#endif
