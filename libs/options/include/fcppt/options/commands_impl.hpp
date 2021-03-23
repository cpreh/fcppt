//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_COMMANDS_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_COMMANDS_IMPL_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/const.hpp>
#include <fcppt/loop.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/commands_decl.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/deref_type.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/indent.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/options/detail/check_sub_command_names.hpp>
#include <fcppt/options/detail/parse_to_empty.hpp>
#include <fcppt/options/detail/split_command.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

template <typename OptionsParser, typename... SubCommands>
template <typename OptionsParserArg, typename... SubCommandsArgs, typename>
fcppt::options::commands<OptionsParser, SubCommands...>::commands(
    OptionsParserArg &&_options_parser, SubCommandsArgs &&..._sub_commands)
    : options_parser_{std::forward<OptionsParserArg>(_options_parser)},
      sub_commands_{std::forward<SubCommandsArgs>(_sub_commands)...}
{
  fcppt::options::detail::check_sub_command_names(fcppt::algorithm::map<std::vector<fcppt::string>>(
      sub_commands_,
      [](auto const &_sub_command) { return fcppt::options::deref(_sub_command).name(); }));
}

template <typename OptionsParser, typename... SubCommands>
fcppt::options::parse_result<
    typename fcppt::options::commands<OptionsParser, SubCommands...>::result_type>
fcppt::options::commands<OptionsParser, SubCommands...>::parse(
    fcppt::options::state &&_state, fcppt::options::parse_context const &) const
{
  auto const parse_inner(
      [this](
          auto const &_sub_command,
          fcppt::args_vector &&_first_args,
          fcppt::args_vector &&_second_args) -> fcppt::options::parse_result<result_type> {
        return fcppt::either::match(
            fcppt::options::detail::parse_to_empty(
                this->options_parser_,
                fcppt::options::state{std::move(_first_args)},
                fcppt::options::parse_context{
                    fcppt::options::deref(this->options_parser_).option_names()}),
            [](fcppt::options::error &&_error) -> fcppt::options::parse_result<result_type> {
              return fcppt::options::parse_result<result_type>{fcppt::options::parse_error{
                  fcppt::options::other_error{std::move(_error.get())}}};
            },
            [&_sub_command,
             &_second_args](fcppt::options::result_of<OptionsParser> &&_options_result)
                -> fcppt::options::parse_result<result_type> {
              using sub_command_type = fcppt::options::deref_type<
                  fcppt::type_traits::remove_cv_ref_t<decltype(_sub_command)>>;

              return fcppt::either::map(
                  fcppt::options::deref(fcppt::options::deref(_sub_command).parser())
                      .parse(
                          fcppt::options::state{std::move(_second_args)},
                          fcppt::options::parse_context{
                              fcppt::options::deref(fcppt::options::deref(_sub_command).parser())
                                  .option_names()}),
                  [&_options_result](
                      fcppt::options::state_with_value<fcppt::options::result_of<
                          typename sub_command_type::parser_type>> &&_parser_result) {
                    return fcppt::options::state_with_value<result_type>{
                        std::move(_parser_result.state()),
                        result_type{
                            fcppt::options::options_label{} = std::move(_options_result),
                            fcppt::options::sub_command_label{} =
                                variant_result{fcppt::options::result_of<sub_command_type>{
                                    typename sub_command_type::tag{} =
                                        std::move(_parser_result.value())}}}};
                  });
            });
      });

  using optional_result_type = fcppt::optional::object<fcppt::options::parse_result<result_type>>;

  return fcppt::optional::maybe(
      fcppt::options::detail::split_command(
          _state.args(), fcppt::options::deref(options_parser_).option_names()),
      [&_state, this] {
        return fcppt::either::make_failure<fcppt::options::state_with_value<result_type>>(
            fcppt::options::parse_error{fcppt::options::missing_error{
                std::move(_state),
                FCPPT_TEXT("No command specified from ") +
                    fcppt::output_to_fcppt_string(
                        fcppt::container::output(fcppt::algorithm::map<std::vector<fcppt::string>>(
                            this->sub_commands_, [](auto const &_parser) -> fcppt::string {
                              return fcppt::options::deref(_parser).name();
                            })))}});
      },
      [this, parse_inner](
          fcppt::tuple::object<fcppt::args_vector, fcppt::string, fcppt::args_vector> &&_split_arguments) {
        return fcppt::optional::from(
            fcppt::algorithm::fold_break(
                this->sub_commands_,
                optional_result_type{},
                [&_split_arguments,
                 parse_inner](auto const &_parser, optional_result_type &&_result) {
                  return fcppt::tuple::get<1>(_split_arguments) == fcppt::options::deref(_parser).name()
                             ? std::make_pair(
                                   fcppt::loop::break_,
                                   optional_result_type{parse_inner(
                                       _parser,
                                       std::move(fcppt::tuple::get<0>(_split_arguments)),
                                       std::move(fcppt::tuple::get<2>(_split_arguments)))})
                             : std::make_pair(fcppt::loop::continue_, std::move(_result));
                }),
            [&_split_arguments] {
              return fcppt::either::make_failure<fcppt::options::state_with_value<result_type>>(
                  fcppt::options::parse_error{fcppt::options::other_error{
                      FCPPT_TEXT("Invalid command ") + std::move(fcppt::tuple::get<1>(_split_arguments))}});
            });
      });
}

template <typename OptionsParser, typename... SubCommands>
fcppt::options::flag_name_set
fcppt::options::commands<OptionsParser, SubCommands...>::flag_names() const
{
  return fcppt::options::flag_name_set{};
}

template <typename OptionsParser, typename... SubCommands>
fcppt::options::option_name_set
fcppt::options::commands<OptionsParser, SubCommands...>::option_names() const
{
  return fcppt::options::option_name_set{};
}

template <typename OptionsParser, typename... SubCommands>
fcppt::string fcppt::options::commands<OptionsParser, SubCommands...>::usage() const
{
  return fcppt::options::deref(options_parser_).usage() + FCPPT_TEXT("\n") +
         fcppt::options::indent(fcppt::algorithm::fold(
             sub_commands_,
             fcppt::string{},
             [](auto const &_sub_command, fcppt::string &&_state) -> fcppt::string {
               return std::move(_state) + fcppt::options::deref(_sub_command).name() +
                      FCPPT_TEXT(": ") +
                      fcppt::optional::maybe(
                          fcppt::options::deref(_sub_command).help_text(),
                          fcppt::const_(fcppt::string{}),
                          [](fcppt::options::help_text const &_help_text) {
                            return FCPPT_TEXT(" (") + _help_text.get() + FCPPT_TEXT(")");
                          }) +
                      fcppt::options::indent([&_sub_command] {
                        fcppt::string inner_usage{
                            fcppt::options::deref(fcppt::options::deref(_sub_command).parser())
                                .usage()};

                        return inner_usage.empty() ? fcppt::string{}
                                                   : FCPPT_TEXT("\n") + std::move(inner_usage);
                      }()) +
                      FCPPT_TEXT("\n");
             }));
}

#endif
