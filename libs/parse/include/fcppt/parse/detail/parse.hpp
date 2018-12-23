//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_PARSE_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_PARSE_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/parse/context_impl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
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
parse(
	Parser const &_parser,
	std::istream &_input,
	fcppt::optional::reference<
		Skipper const
	> const _skipper
)
{
	fcppt::parse::state state{
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
				_skipper
			}
		);
}

}
}
}

#endif
