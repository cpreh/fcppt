//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/loop.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/repetition_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/parse/skipper/run.hpp>
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
		fcppt::parse::basic_stream<
			Ch
		>
	> const _state,
	Skipper const &_skipper
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

	fcppt::parse::error<
		Ch
	> error{
		fcppt::either::loop(
			[
				this,
				_state,
				&_skipper
			]{
				return
					fcppt::either::bind(
						fcppt::parse::deref(
							this->parser_
						).parse(
							_state,
							_skipper
						),
						[
							_state,
							&_skipper
						](
							fcppt::parse::result_of<
								Parser
							> &&_element
						)
						{
							return
								fcppt::either::map(
									fcppt::parse::skipper::run(
										_skipper,
										_state
									),
									[
										&_element
									](
										fcppt::unit const &
									)
									{
										return
											std::move(
												_element
											);
									}
								);
						}
					);
			},
			[
				_state,
				&result,
				&pos
			](
				fcppt::parse::result_of<
					Parser
				> &&_element
			)
			{
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
		)
	};

	fcppt::parse::set_position(
		_state,
		pos
	);

	return
		error.is_fatal()
		?
			fcppt::either::make_failure<
				result_type
			>(
				std::move(
					error
				)
			)
		:
			fcppt::parse::make_success<
				Ch
			>(
				std::move(
					result
				)
			)
		;
}

#endif
