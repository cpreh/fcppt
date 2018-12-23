//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PARSE_NOSKIP_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_NOSKIP_HPP_INCLUDED

#include <fcppt/optional/make.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/parse.hpp>
#include <fcppt/parse/detail/no_skipper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser
>
fcppt::parse::result<
	fcppt::parse::result_of<
		Parser
	>
>
parse_noskip(
	Parser const &_parser,
	std::istream &_input
)
{
	return
		fcppt::parse::detail::parse(
			_parser,
			_input,
			fcppt::optional::reference<
				fcppt::parse::detail::no_skipper const
			>()
		);
}

}
}

#endif
