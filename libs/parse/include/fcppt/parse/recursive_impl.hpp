//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_RECURSIVE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_RECURSIVE_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/recursive_impl.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/recursive_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::recursive<
	Parser
>::recursive(
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
	fcppt::parse::recursive<
		Parser
	>::result_type
>
fcppt::parse::recursive<
	Parser
>::parse(
	fcppt::reference<
		fcppt::parse::basic_stream<
			Ch
		>
	> const _state,
	Skipper const &_skipper
) const
{
	return
		fcppt::parse::construct<
			fcppt::recursive<
				fcppt::parse::result_of<
					Parser
				>
			>
		>(
			fcppt::make_cref(
				fcppt::parse::deref(
					this->parser_
				)
			)
		).parse(
			_state,
			_skipper
		);
}

#endif
