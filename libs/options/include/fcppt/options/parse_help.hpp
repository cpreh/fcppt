//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_HELP_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_HELP_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/help_switch.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/detail/help_label.hpp>
#include <fcppt/record/get.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Parse a command-line with a help parser.

\ingroup fcpptoptions

First, the parser \a _help is applied to \a _args. If it matches, the
<code>usage</code> string is gathered from \a _parser and returned. If \a _help
fails, then the result of applying \a _parser to \a _args is returned.

\warning Do not include any short or long names in \a _parser that \a _help is using.
*/
template<
	typename Parser
>
fcppt::options::help_result<
	typename
	Parser::result_type
>
parse_help(
	fcppt::options::help_switch const &_help,
	Parser const &_parser,
	fcppt::args_vector const &_args
)
{
	typedef
	fcppt::options::help_result<
		typename
		Parser::result_type
	>
	result_type;

	// TODO: Can we optimize this?
	return
		fcppt::either::match(
			fcppt::options::parse(
				_help,
				_args
			),
			[
				&_parser,
				&_args
			](
				fcppt::options::error const &
			)
			{
				return
					result_type{
						fcppt::options::parse(
							_parser,
							_args
						)
					};
			},
			[
				&_parser,
				&_args
			](
				fcppt::options::help_switch::result_type const &_value
			)
			{
				return
					fcppt::record::get<
						fcppt::options::detail::help_label
					>(
						_value
					)
					?
						result_type{
							fcppt::options::help_text{
								_parser.usage()
							}
						}
					:
						result_type{
							fcppt::options::parse(
								_parser,
								_args
							)
						}
					;
			}
		);
}

}
}

#endif
