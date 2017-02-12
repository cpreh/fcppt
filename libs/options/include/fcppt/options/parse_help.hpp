//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_HELP_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_HELP_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/help_switch.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/detail/deref.hpp>
#include <fcppt/options/detail/help_error.hpp>
#include <fcppt/options/detail/help_label.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>
#include <fcppt/options/detail/parse.hpp>
#include <fcppt/options/detail/parse_result.hpp>
#include <fcppt/options/detail/parse_to_empty.hpp>
#include <fcppt/options/detail/state_from_args.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Parse a command-line with a help parser.

\ingroup fcpptoptions

First, the switch parser \a _help is applied to \a _args. If its switch <b>and
nothing else</b> is specified, the <code>usage</code> string is gathered from
\a _parser and returned.  Otherwise, if the switch of \a _help was not
specified, then the result of applying \a _parser to \a _args is returned.

\warning Do not include any short or long names in \a _parser that \a _help is using.
*/
template<
	typename Parser
>
fcppt::options::help_result<
	fcppt::options::result_of<
		Parser
	>
>
parse_help(
	fcppt::options::help_switch const &_help,
	Parser const &_parser,
	fcppt::args_vector const &_args
)
{
	typedef
	fcppt::options::result_of<
		Parser
	>
	result_type;

	typedef
	fcppt::options::help_result<
		result_type
	>
	return_type;

	return
		fcppt::either::match(
			fcppt::options::detail::parse(
				_help,
				fcppt::options::detail::state_from_args(
					_args,
					fcppt::options::detail::deref(
						_parser
					).parameters()
				)
			),
			[](
				fcppt::options::error &&_error
			)
			{
				return
					return_type{
						fcppt::either::make_failure<
							result_type
						>(
							std::move(
								_error
							)
						)
					};
			},
			[
				&_parser,
				&_help
			](
				fcppt::options::detail::parse_result<
					fcppt::options::result_of<
						fcppt::options::help_switch
					>
				> &&_result
			)
			{
				return
					fcppt::record::get<
						fcppt::options::detail::help_label
					>(
						_result.value()
					)
					?
						_result.remaining_state().empty()
						?
							return_type{
								fcppt::options::help_text{
									fcppt::options::detail::deref(
										_parser
									).usage()
								}
							}
						:
							return_type{
								fcppt::either::make_failure<
									result_type
								>(
									fcppt::options::error{
										fcppt::options::other_error{
											FCPPT_TEXT("The help option ")
											+
											fcppt::options::detail::long_or_short_name(
												_help.long_name(),
												_help.short_name()
											)
											+
											FCPPT_TEXT(" cannot be specified with other options at the same time.")
										}
									}
								)
							}
					:
						return_type{
							fcppt::either::match(
								fcppt::options::detail::parse_to_empty(
									_parser,
									std::move(
										_result.remaining_state()
									)
								),
								[
									&_help
								](
									fcppt::options::error &&_error
								)
								{
									return
										fcppt::either::make_failure<
											result_type
										>(
											fcppt::options::detail::help_error(
												_help,
												std::move(
													_error
												)
											)
										);
								},
								[](
									result_type &&_inner_result
								)
								{
									return
										fcppt::either::make_success<
											fcppt::options::error
										>(
											std::move(
												_inner_result
											)
										);
								}
							)
						}
					;
			}
		);
}

}
}

#endif
