//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_BASIC_INT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_BASIC_INT_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/digits.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/detail/basic_int_decl.hpp>
#include <fcppt/parse/operators/repetition_plus.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
fcppt::parse::detail::basic_int<
	Type
>::basic_int()
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
	fcppt::parse::detail::basic_int<
		Type
	>::result_type
>
fcppt::parse::detail::basic_int<
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
		+
		fcppt::parse::digits<
			Ch
		>()
	};

	return
		fcppt::either::bind(
			parser.parse(
				_state,
				_context
			),
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
											"Failed to parse integer from "
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
