//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_COMMANDS_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_COMMANDS_IMPL_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/const.hpp>
#include <fcppt/loop.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/commands_decl.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/options/detail/split_command.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename OptionsParser,
	typename... SubCommands
>
template<
	typename OptionsParserArg,
	typename... SubCommandsArgs
>
fcppt::options::commands<
	OptionsParser,
	SubCommands...
>::commands(
	OptionsParserArg &&_options_parser,
	SubCommandsArgs &&... _sub_commands
)
:
	options_parser_{
		std::forward<
			OptionsParserArg
		>(
			_options_parser
		)
	},
	sub_commands_{
		std::forward<
			SubCommandsArgs
		>(
			_sub_commands
		)...
	}
{
}

template<
	typename OptionsParser,
	typename... SubCommands
>
fcppt::options::result<
	typename
	fcppt::options::commands<
		OptionsParser,
		SubCommands...
	>::result_type
>
fcppt::options::commands<
	OptionsParser,
	SubCommands...
>::parse(
	fcppt::options::parse_arguments &_arguments
) const
{
	auto const parse_inner(
		[
			this,
			&_arguments
		](
			auto const &_parser,
			std::pair<
				fcppt::args_vector,
				fcppt::args_vector
			> &&_split_args
		)
		->
		fcppt::options::result<
			result_type
		>
		{
			fcppt::options::parse_arguments option_args{
				fcppt::options::state{
					std::move(
						_split_args.first
					)
				},
				// TODO: move?
				fcppt::options::option_name_set{
					_arguments.option_names_
				}
			};

			return
				fcppt::either::bind(
					fcppt::options::deref(
						this->options_parser_
					).parse(
						option_args
					),
					[
						&_parser,
						&_split_args,
						&_arguments
					](
						auto &&_options_result
					)
					->
					fcppt::options::result<
						result_type
					>
					{
						// TODO: Move state
						_arguments.state_ =
							fcppt::options::state{
								std::move(
									_split_args.second
								)
							};

						return
							fcppt::either::map(
								fcppt::options::deref(
									fcppt::options::deref(
										_parser
									).parser()
								).parse(
									_arguments
								),
								[
									&_options_result
								](
									auto &&_parser_result
								)
								{
									return
										result_type{
											fcppt::options::options_label{} =
												std::move(
													_options_result
												),
											fcppt::options::sub_command_label{} =
												variant_result{
													std::move(
														_parser_result
													)
												}
										};
								}
							);
					}
				);
		}
	);

	fcppt::options::parse_arguments const option_arguments{
		fcppt::options::state{
			_arguments.state_
		},
		fcppt::options::deref(
			options_parser_
		).option_names()
	};

	typedef
	fcppt::optional::object<
		fcppt::options::result<
			result_type
		>
	>
	optional_result_type;

	return
		fcppt::optional::from(
			fcppt::algorithm::fold_break(
				sub_commands_,
				optional_result_type{},
				[
					parse_inner,
					&option_arguments
				](
					auto const &_parser,
					optional_result_type &&_result
				)
				{
					return
						fcppt::optional::maybe(
							fcppt::options::detail::split_command(
								option_arguments,
								fcppt::options::deref(
									_parser
								).name()
							),
							[
								&_result
							]{
								return
									std::make_pair(
										fcppt::loop::continue_,
										std::move(
											_result
										)
									);
							},
							[
								parse_inner,
								&_parser
							](
								std::pair<
									fcppt::args_vector,
									fcppt::args_vector
								> &&_split_args
							)
							{
								return
									std::make_pair(
										fcppt::loop::break_,
										optional_result_type{
											parse_inner(
												_parser,
												std::move(
													_split_args
												)
											)
										}
									);
							}
						);
				}
			),
			[
				this
			]{
				return
					fcppt::either::make_failure<
						result_type
					>(
						fcppt::options::error{
							fcppt::options::missing_error{
								FCPPT_TEXT("No command specified from [")
								+
								fcppt::algorithm::fold(
									this->sub_commands_,
									fcppt::string{},
									[](
										auto const &_parser,
										fcppt::string &&_state
									)
									->
									fcppt::string
									{
										return
											std::move(
												_state
											)
											+
											fcppt::options::deref(
												_parser
											).name()
											+
											// TODO
											FCPPT_TEXT(", ");
									}
								)
								+
								FCPPT_TEXT("]")
							}
						}
					);
			}
		);
}

template<
	typename OptionsParser,
	typename... SubCommands
>
fcppt::options::flag_name_set
fcppt::options::commands<
	OptionsParser,
	SubCommands...
>::flag_names() const
{
	return
		fcppt::options::flag_name_set{
			fcppt::options::name_set{}
		};
}

template<
	typename OptionsParser,
	typename... SubCommands
>
fcppt::options::option_name_set
fcppt::options::commands<
	OptionsParser,
	SubCommands...
>::option_names() const
{
	return
		fcppt::options::option_name_set{
			fcppt::options::name_set{}
		};
}

template<
	typename OptionsParser,
	typename... SubCommands
>
fcppt::string
fcppt::options::commands<
	OptionsParser,
	SubCommands...
>::usage() const
{
	return
		fcppt::options::deref(
			options_parser_
		).usage()
		+
		FCPPT_TEXT("\n")
		+
		fcppt::algorithm::fold(
			sub_commands_,
			fcppt::string{},
			[](
				auto const &_sub_command,
				fcppt::string &&_state
			)
			->
			fcppt::string
			{
				return
					std::move(
						_state
					)
					+
					fcppt::options::deref(
						_sub_command
					).name()
					+
					FCPPT_TEXT(": ")
					+
					fcppt::options::deref(
						fcppt::options::deref(
							_sub_command
						).parser()
					).usage()
					+
					fcppt::optional::maybe(
						fcppt::options::deref(
							_sub_command
						).help_text(),
						fcppt::const_(
							fcppt::string{}
						),
						[](
							fcppt::options::help_text const &_help_text
						)
						{
							return
								FCPPT_TEXT(" (")
								+
								_help_text.get()
								+
								FCPPT_TEXT(")");
						}
					)
					+
					FCPPT_TEXT("\n");
			}
		);
}

#endif
