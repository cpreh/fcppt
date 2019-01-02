//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_PLUS_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_PLUS_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/repetition_plus_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
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
	return
		fcppt::optional::bind(
			this->parser_.parse(
				_state,
				_context
			),
			[](
				result_type &&_result
			)
			{
				return
					fcppt::optional::make_if(
						!_result.empty(),
						[
							&_result
						]{
							return
								std::move(
									_result
								);
						}
					);
			}
		);
}

#endif
