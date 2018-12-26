//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/repetition_decl.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::repetition<
	Parser
>::repetition(
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
	fcppt::parse::repetition<
		Parser
	>::result_type
>
fcppt::parse::repetition<
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
	typename
	fcppt::parse::state<
		Ch
	>::pos_type pos{
		_state.get().stream().tellg()
	};

	result_type result{};

	// TODO: This code is terrible
	for(;;)
	{
		fcppt::parse::result<
			fcppt::parse::result_of<
				Parser
			>
		> element{
			fcppt::parse::deref(
				this->parser_
			).parse(
				_state,
				_context
			)
		};

		if(
			!element.has_value()
		)
			break;

		pos =
			_state.get().stream().tellg();

		result.push_back(
			std::move(
				element.get_unsafe()
			)
		);
	}

	// TODO: Do we have to do error handling in case pos == pos_type(-1)?
	_state.get().stream().seekg(
		pos
	);

	return
		fcppt::optional::make(
			std::move(
				result
			)
		);
}

#endif
