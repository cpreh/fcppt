//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_FLOAT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FLOAT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/float_decl.hpp>
#include <fcppt/parse/get.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
fcppt::parse::float_<
	Type
>::float_()
{
}

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
	fcppt::parse::float_<
		Type
	>::result_type
>
fcppt::parse::float_<
	Type
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
			fcppt::parse::get<
				Type
			>(
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
								"Expected float"
							)
						}
					};
			}
		);
}

#endif
