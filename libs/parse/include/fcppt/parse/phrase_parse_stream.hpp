//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PHRASE_PARSE_STREAM_HPP_INCLUDED
#define FCPPT_PARSE_PHRASE_PARSE_STREAM_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/parse/phrase_parse.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/stream_impl.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
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
[[nodiscard]]
fcppt::parse::result<
	Ch,
	fcppt::parse::result_of<
		Parser
	>
>
phrase_parse_stream(
	Parser const &_parser,
	std::basic_istream<
		Ch
	> &_input,
	Skipper const &_skipper
)
{
	static_assert(
		fcppt::parse::is_parser<
			Parser
		>::value
	);

	static_assert(
		fcppt::parse::skipper::is_skipper<
			Skipper
		>::value
	);

	fcppt::parse::detail::stream<
		Ch
	> stream{
		fcppt::make_ref(
			_input
		)
	};

	return
		fcppt::parse::phrase_parse(
			_parser,
			stream,
			_skipper
		);
}

}
}

#endif
