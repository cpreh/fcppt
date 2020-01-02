//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/parse/basic_char_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::basic_char<
	Ch
>::basic_char()
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
	fcppt::parse::basic_char<
		Ch
	>::result_type
>
fcppt::parse::basic_char<
	Ch
>::parse(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &
) const
{
	return
		fcppt::either::from_optional(
			fcppt::parse::get_char(
				_state
			),
			[]{
				return
					fcppt::parse::error<
						Ch
					>{
						std::basic_string<
							Ch
						>{
							FCPPT_STRING_LITERAL(
								Ch,
								"EOF"
							)
						}
					};
			}
		);
}

#endif
