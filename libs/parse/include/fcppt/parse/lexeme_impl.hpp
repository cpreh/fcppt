//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_LEXEME_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_LEXEME_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/context_impl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/lexeme_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::lexeme<
	Parser
>::lexeme(
	Parser &&_parser
)
:
	parser_{
		std::move(
			_parser
		)
	}
{
}

template<
	typename Parser
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::lexeme<
		Parser
	>::result_type
>
fcppt::parse::lexeme<
	Parser
>::parse(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &
) const
{
	fcppt::parse::epsilon const skipper{};

	fcppt::parse::context<
		fcppt::parse::epsilon
	> const context{
		fcppt::make_cref(
			skipper
		)
	};

	return
		fcppt::parse::deref(
			this->parser_
		).parse(
			_state,
			context
		);
}

#endif
