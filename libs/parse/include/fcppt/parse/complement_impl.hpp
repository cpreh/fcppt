//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_COMPLEMENT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_COMPLEMENT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/complement_decl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::complement<
	Parser
>::complement(
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
	typename
	fcppt::parse::complement<
		Parser
	>::result_type
>
fcppt::parse::complement<
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
	return
		fcppt::optional::maybe(
			fcppt::parse::deref(
				this->parser_
			).parse(
				_state,
				_context
			),
			[]{
				return
					fcppt::optional::make(
						fcppt::unit{}
					);
			},
			[](
				fcppt::parse::result_of<
					Parser
				> const &
			)
			{
				return
					fcppt::parse::result<
						result_type
					>{};
			}
		);
}

#endif
