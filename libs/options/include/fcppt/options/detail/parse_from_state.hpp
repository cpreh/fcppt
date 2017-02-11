//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_PARSE_FROM_STATE_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_PARSE_FROM_STATE_HPP_INCLUDED

#include <fcppt/either/map.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/detail/parse_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Parser
>
inline
fcppt::options::result<
	fcppt::options::detail::parse_result<
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
					fcppt::options::detail::parse_result<
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
}

#endif
