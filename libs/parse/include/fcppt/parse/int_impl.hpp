//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_INT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_INT_IMPL_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/monad.hpp>
#include <fcppt/monad/do.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/int_decl.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/make_literal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/detail/basic_int_impl.hpp>
#include <fcppt/parse/operators/optional.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
fcppt::parse::int_<
	Type
>::int_()
= default;

template<
	typename Type
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::int_<
		Type
	>::result_type
>
fcppt::parse::int_<
	Type
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
		fcppt::parse::make_lexeme(
			-
			fcppt::parse::make_literal(
				FCPPT_CHAR_LITERAL(Ch, '-')
			)
			>>
			fcppt::parse::detail::basic_int<
				Type
			>{}
		)
	};

	return
		fcppt::monad::do_(
			fcppt::parse::run_skipper(
				_state,
				_context
			),
			[
				&parser,
				&_state,
				&_context
			](
				fcppt::unit
			)
			{
				return
					parser.parse(
						_state,
						_context
					);
			},
			[](
				fcppt::parse::result_of<
					decltype(
						parser
					)
				> const &_result
			)
			{
				Type const value{
					std::get<1>(
						_result
					)
				};

				return
					fcppt::parse::make_success<
						Ch
					>(
						std::get<0>(
							_result
						).has_value()
						?
							-value
						:
							value
					);
			}
		);
}

#endif
