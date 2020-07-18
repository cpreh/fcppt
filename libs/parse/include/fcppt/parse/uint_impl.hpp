//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_UINT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_UINT_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/monad.hpp>
#include <fcppt/monad/do.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/digits.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/uint_decl.hpp>
#include <fcppt/parse/operators/repetition_plus.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
fcppt::parse::uint_<
	Type
>::uint_()
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
	fcppt::parse::uint_<
		Type
	>::result_type
>
fcppt::parse::uint_<
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
			+
			fcppt::parse::digits<
				Ch
			>()
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
				return
					fcppt::either::from_optional(
						fcppt::extract_from_string<
							Type
						>(
							_result
						),
						[
							&_result
						]{
							return
								fcppt::parse::error<
									Ch
								>{
									std::basic_string<
										Ch
									>{
										FCPPT_STRING_LITERAL(
											Ch,
											"Failed to parse unsigned integer from "
										)
									}
									+
									_result
								};
						}
					);
			}
		);
}

#endif
