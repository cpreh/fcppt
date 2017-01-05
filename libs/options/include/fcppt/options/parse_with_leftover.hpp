//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_WITH_LEFTOVER_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_WITH_LEFTOVER_HPP_INCLUDED

#include <fcppt/either/map.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_from_args.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Parser
>
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
	fcppt::options::state state{
		fcppt::options::state_from_args(
			_args,
			_parser.parameters()
		)
	};

	typedef
	typename
	Parser::result_type
	result_type;

	return
		fcppt::either::map(
			_parser.parse(
				state
			),
			[
				&state
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
							state
						)
					};
			}
		);
}

}
}

#endif
