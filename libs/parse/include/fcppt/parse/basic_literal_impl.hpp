//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_literal_decl.hpp>
#include <fcppt/parse/char_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::basic_literal<
	Ch
>::basic_literal(
	Ch const _ch
)
:
	ch_{
		_ch
	}
{
}

template<
	typename Ch
>
template<
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::basic_literal<
		Ch
	>::result_type
>
fcppt::parse::basic_literal<
	Ch
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
	fcppt::parse::basic_char<
		Ch
	> const parser{};

	return
		fcppt::either::bind(
			parser.parse(
				_state,
				_context
			),
			[
				this
			](
				Ch const _ch
			)
			{
				return
					_ch
					==
					this->ch_
					?
						fcppt::parse::make_success<
							Ch
						>(
							fcppt::unit{}
						)
					:
						fcppt::either::make_failure<
							result_type
						>(
							fcppt::parse::error<
								Ch
							>{
								std::basic_string<
									Ch
								>{
									FCPPT_STRING_LITERAL(
										Ch,
										"Expected "
									)
								}
								+
								this->ch_
								+
								std::basic_string<
									Ch
								>{
									FCPPT_STRING_LITERAL(
										Ch,
										", got "
									)
								}
								+
								_ch
							}
						)
					;
			}
		);
}

#endif
