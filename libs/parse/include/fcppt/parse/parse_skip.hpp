//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PARSE_SKIP_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_SKIP_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/parse.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser,
	typename Skipper
>
fcppt::parse::result<
	fcppt::parse::result_of<
		Parser
	>
>
parse_skip(
	Parser const &_parser,
	std::istream &_input,
	Skipper const &_skipper
)
{
	return
		fcppt::parse::detail::parse(
			_parser,
			_input,
			fcppt::optional::make(
				fcppt::make_cref(
					_skipper
				)
			)
		);
}

}
}

#endif
