//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MAKE_COMMANDS_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_COMMANDS_HPP_INCLUDED

#include <fcppt/options/commands_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief Makes a commands parser.

\ingroup fcpptoptions

\tparam SubCommands A parameter pack of #fcppt::options::sub_command.
*/
template <typename OptionsParser, typename... SubCommands>
inline fcppt::options::
    commands<std::remove_cvref_t<OptionsParser>, std::remove_cvref_t<SubCommands>...>
    make_commands(OptionsParser &&_options_parser, SubCommands &&..._sub_commands)
{
  return fcppt::options::
      commands<std::remove_cvref_t<OptionsParser>, std::remove_cvref_t<SubCommands>...>{
          std::forward<OptionsParser>(_options_parser),
          std::forward<SubCommands>(_sub_commands)...};
}
}

#endif
