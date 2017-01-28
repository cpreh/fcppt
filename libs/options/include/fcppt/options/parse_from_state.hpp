//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_FROM_STATE_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_FROM_STATE_HPP_INCLUDED

#include <fcppt/either/map.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Parse from a state and return the leftover state.

\ingroup fcpptoptions

Applies \a _parser to \a _state. If that succeeds, then the result plus the
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
parse_from_state(
	Parser const &_parser,
	fcppt::options::state &&_state
)
{
	typedef
	typename
	Parser::result_type
	result_type;

	return
		fcppt::either::map(
			_parser.parse(
				_state
			),
			[
				&_state
			](
				result_type &&_result
			)
			{
				return
					fcppt::options::parse_result<
						result_type
					>{
						std::move(
							_result
						),
						std::move(
							_state
						)
					};
			}
		);
}

}
}

#endif
