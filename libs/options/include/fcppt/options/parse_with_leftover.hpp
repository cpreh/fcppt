//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_WITH_LEFTOVER_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_WITH_LEFTOVER_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/parse_from_state.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state_from_args.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Parse a command-line and return the leftover state.

\ingroup fcpptoptions

Applies \a _parser to \a _args. If that succeeds, then the result plus the
leftover state is returned. Otherwise, the error of the parse is returned.
*/
template<
	typename Parser
>
inline
fcppt::options::result<
	fcppt::options::parse_result<
		typename
		Parser::result_type
	>
>
parse_with_leftover(
	Parser const &_parser,
	fcppt::args_vector const &_args
)
{
	return
		fcppt::options::parse_from_state(
			_parser,
			fcppt::options::state_from_args(
				_args,
				_parser.parameters()
			)
		);
}

}
}

#endif
