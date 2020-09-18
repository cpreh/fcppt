//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_char_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/get_char_error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>


template<
	typename Ch
>
fcppt::parse::basic_char<
	Ch
>::basic_char()
= default;

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
		fcppt::parse::get_char_error(
			_state
		);
}

#endif
