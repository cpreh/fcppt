//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/leftover_error.hpp>
#include <fcppt/options/detail/parse_from_state.hpp>
#include <fcppt/options/detail/parse_result.hpp>
#include <fcppt/options/detail/state_from_args.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Parse a command-line.

\ingroup fcpptoptions

Applies \a _parser to \a _args.
*/
template<
	typename Parser
>
fcppt::options::result<
	typename
	Parser::result_type
>
parse(
	Parser const &_parser,
	fcppt::args_vector const &_args
)
{
	typedef
	typename
	Parser::result_type
	result_type;

	return
		fcppt::either::bind(
			fcppt::options::detail::parse_from_state(
				_parser,
				fcppt::options::detail::state_from_args(
					_args,
					_parser.parameters()
				)
			),
			[](
				fcppt::options::detail::parse_result<
					result_type
				> &&_result
			)
			{
				typedef
				fcppt::options::result<
					typename
					Parser::result_type
				>
				return_type;

				fcppt::options::state const &state{
					_result.remaining_state()
				};

				return
					state.empty()
					?
						return_type{
							std::move(
								_result.value()
							)
						}
					:
						return_type{
							fcppt::options::error{
								fcppt::options::other_error{
									fcppt::options::detail::leftover_error(
										state
									)
								}
							}
						}
					;
			}
		);
}

}
}

#endif
