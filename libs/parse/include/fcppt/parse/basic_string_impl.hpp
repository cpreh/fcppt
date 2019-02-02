//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_STRING_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STRING_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/basic_string_decl.hpp>
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
fcppt::parse::basic_string<
	Ch
>::basic_string(
	std::basic_string<
		Ch
	> &&_string
)
:
	string_{
		std::move(
			_string
		)
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
	fcppt::parse::basic_string<
		Ch
	>::result_type
>
fcppt::parse::basic_string<
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
	> const impl{};

	for(
		Ch const elem
		:
		this->string_
	)
	{
		if(
			impl.parse(
				_state,
				_context
			)
			!=
			fcppt::parse::make_success<
				Ch
			>(
				elem
			)
		)
			return
				fcppt::either::make_failure<
					result_type
				>(
					fcppt::parse::error<
						Ch
					>{
						FCPPT_STRING_LITERAL(
							Ch,
							"Expected "
						)
						+
						this->string_
					}
				);
	}

	return
		fcppt::parse::make_success<
			Ch
		>(
			fcppt::unit{}
		);
}

#endif
