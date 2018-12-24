//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PARSE_STRING_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STRING_HPP_INCLUDED

#include <fcppt/parse/parse_stream.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
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
	std::basic_istringstream<
		Ch
	> stream{
		std::move(
			_string
		)
	};

	return
		fcppt::parse::parse_stream(
			_parser,
			stream,
			_skipper
		);
}

}
}

#endif
