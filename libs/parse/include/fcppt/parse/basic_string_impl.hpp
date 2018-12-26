//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_STRING_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STRING_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/basic_string_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result.hpp>
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
	},
	impl_{
		fcppt::parse::basic_char<
			Ch
		>{}
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
	return
		fcppt::optional::bind(
			fcppt::parse::deref(
				this->impl_
			).parse(
				_state,
				_context
			),
			[
				this
			](
				std::basic_string<
					Ch
				> const &_result
			)
			{
				return
					fcppt::optional::make_if(
						this->string_
						==
						_result,
						fcppt::const_(
							fcppt::unit{}
						)
					);
			}
		);
}

#endif
