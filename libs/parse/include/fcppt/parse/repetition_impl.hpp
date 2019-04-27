//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/loop.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/repetition_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/parse/state_fwd.hpp>
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
	Ch,
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
	fcppt::parse::position<
		Ch
	> pos{
		fcppt::parse::get_position(
			_state
		)
	};

	result_type result{};

	fcppt::either::loop(
		[
			this,
			_state,
			&_context
		]{
			return
				fcppt::parse::deref(
					this->parser_
				).parse(
					_state,
					_context
				);
		},
		[
			_state,
			&_context,
			&result,
			&pos
		](
			fcppt::parse::result_of<
				Parser
			> &&_element
		)
		{
			fcppt::parse::run_skipper(
				_state,
				_context
			);

			pos =
				fcppt::parse::get_position(
					_state
				);

			result.push_back(
				std::move(
					_element
				)
			);
		}
	);

	fcppt::parse::set_position(
		_state,
		pos
	);

	return
		fcppt::parse::make_success<
			Ch
		>(
			std::move(
				result
			)
		);
}

#endif
