//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_NAMED_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_NAMED_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/named_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch,
	typename Parser
>
fcppt::parse::named<
	Ch,
	Parser
>::named(
	Parser &&_parser,
	std::basic_string<
		Ch
	> &&_name
)
:
	parser_{
		std::move(
			_parser
		)
	},
	name_{
		std::move(
			_name
		)
	}
{
}

template<
	typename Ch,
	typename Parser
>
template<
	typename Skipper
>
fcppt::parse::result<
	typename
	fcppt::parse::named<
		Ch,
		Parser
	>::result_type
>
fcppt::parse::named<
	Ch,
	Parser
>::parse(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &_context
) const
{
	// TODO:
	return
		this->parser_.parse(
			_state,
			_context
		);
}

#endif
