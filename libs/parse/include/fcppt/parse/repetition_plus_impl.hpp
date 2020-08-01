//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_PLUS_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_PLUS_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/container/join.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/repetition_plus_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::repetition_plus<
	Parser
>::repetition_plus(
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
	fcppt::parse::repetition_plus<
		Parser
	>::result_type
>
fcppt::parse::repetition_plus<
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
	auto const parser{
		fcppt::make_cref(
			fcppt::parse::deref(
				this->parser_
			)
		)
		>>
		*
		fcppt::make_cref(
			fcppt::parse::deref(
				this->parser_
			)
		)
	};

	return
		fcppt::either::map(
			parser.parse(
				_state,
				_context
			),
			[](
				fcppt::parse::result_of<
					decltype(
						parser
					)
				> &&_result
			)
			{
				// TODO(philipp): Should we reverse this so that push_back works?
				return
					fcppt::container::join(
						result_type{
							std::move(
								std::get<0>(
									_result
								)
							)
						},
						std::move(
							std::get<1>(
								_result
							)
						)
					);
			}
		);
}

#endif
