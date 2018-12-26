//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/optional_decl.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::optional<
	Parser
>::optional(
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
	fcppt::parse::optional<
		Parser
	>::result_type
>
fcppt::parse::optional<
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
						result_type{}
					);
			},
			[](
				fcppt::parse::result_of<
					Parser
				> &&_result
			)
			{
				return
					fcppt::optional::make(
						result_type{
							std::move(
								_result
							)
						}
					);
			}
		);
}

#endif
