//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_PARSE_TO_EMPTY_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_PARSE_TO_EMPTY_HPP_INCLUDED

#include <fcppt/either/bind.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/leftover_error.hpp>
#include <fcppt/options/detail/parse.hpp>
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
fcppt::options::result<
	fcppt::options::result_of<
		Parser
	>
>
parse_to_empty(
	Parser const &_parser,
	fcppt::options::state &&_state
)
{
	typedef
	fcppt::options::result_of<
		Parser
	>
	result_type;

	return
		fcppt::either::bind(
			fcppt::options::detail::parse(
				_parser,
				std::move(
					_state
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
					result_type
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
}

#endif
