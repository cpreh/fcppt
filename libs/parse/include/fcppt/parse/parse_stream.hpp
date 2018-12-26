//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PARSE_STREAM_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STREAM_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/parse/context_impl.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
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
	fcppt::parse::result_of<
		Parser
	>
>
parse_stream(
	Parser const &_parser,
	std::basic_istream<
		Ch
	> &_input,
	Skipper const &_skipper
)
try
{
	fcppt::parse::state<
		Ch
	> state{
		fcppt::make_ref(
			_input
		)
	};

	return
		_parser.parse(
			fcppt::make_ref(
				state
			),
			fcppt::parse::context<
				Skipper
			>{
				fcppt::make_cref(
					_skipper
				)
			}
		);
}
catch(
	fcppt::parse::detail::exception const &
)
{
	// TODO: Return an either here
	return
		fcppt::parse::result<
			fcppt::parse::result_of<
				Parser
			>
		>{};
}

}
}

#endif
