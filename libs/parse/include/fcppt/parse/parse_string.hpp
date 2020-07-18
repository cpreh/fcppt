//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PARSE_STRING_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STRING_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/io/stream_to_string.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/is_skipper.hpp>
#include <fcppt/parse/is_valid_argument.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_stream.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <sstream>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch,
	typename Parser,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	fcppt::parse::result_of<
		Parser
	>
>
parse_string(
	Parser const &_parser,
	std::basic_string<
		Ch
	> &&_string,
	Skipper const &_skipper
)
{
	static_assert(
		fcppt::parse::is_valid_argument<
			Parser
		>::value
	);

	static_assert(
		fcppt::parse::is_skipper<
			Skipper
		>::value
	);

	std::basic_istringstream<
		Ch
	> stream{ // NOLINT(fuchsia-default-arguments-calls)
		std::move(
			_string
		)
	};

	stream.unsetf(
		std::ios_base::skipws
	);

	return
		fcppt::either::match(
			fcppt::parse::parse_stream(
				_parser,
				stream,
				_skipper
			),
			[
				&stream
			](
				fcppt::parse::error<
					Ch
				> &&_failure
			)
			{
				return
					fcppt::either::make_failure<
						fcppt::parse::result_of<
							Parser
						>
					>(
						fcppt::parse::error<
							Ch
						>{
							std::move(
								_failure.get()
							)
							+
							FCPPT_STRING_LITERAL(
								Ch,
								". Remaining input: \""
							)
							+
							fcppt::optional::from(
								fcppt::io::stream_to_string(
									stream
								),
								[]{
									return
										std::basic_string<
											Ch
										>{
											FCPPT_STRING_LITERAL(
												Ch,
												"Failed to read remaining input!"
											)
										};
								}
							)
							+
							FCPPT_STRING_LITERAL(
								Ch,
								"\""
							)
						}
					);
			},
			[
				&stream
			](
				fcppt::parse::result_of<
					Parser
				> &&_result
			)
			{
				return
					fcppt::optional::maybe(
						fcppt::io::stream_to_string(
							stream
						),
						[]{
							return
								fcppt::either::make_failure<
									fcppt::parse::result_of<
										Parser
									>
								>(
									fcppt::parse::error<
										Ch
									>{
										FCPPT_STRING_LITERAL(
											Ch,
											"Failed to read remaining input."
										)
									}
								);
						},
						[
							&_result
						](
							std::basic_string<
								Ch
							> &&_rest
						)
						{
							return
								_rest.empty()
								?
									fcppt::parse::make_success<
										Ch
									>(
										std::move(
											_result
										)
									)
								:
									fcppt::either::make_failure<
										fcppt::parse::result_of<
											Parser
										>
									>(
										fcppt::parse::error<
											Ch
										>{
											FCPPT_STRING_LITERAL(
												Ch,
												"Failed to consume remaining input: \""
											)
											+
											std::move(
												_rest
											)
											+
											FCPPT_STRING_LITERAL(
												Ch,
												"\""
											)
										}
									)
								;
						}
					);
			}
		);
}

}
}

#endif
