//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SKIPPER_BASIC_LITERAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_LITERAL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/parse/get_char_error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/skipper/basic_literal_decl.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/detail/expected.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::skipper::basic_literal<
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
fcppt::parse::skipper::result<
	Ch
>
fcppt::parse::skipper::basic_literal<
	Ch
>::skip(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state
) const
{
	return
		fcppt::either::bind(
			fcppt::parse::get_char_error(
				_state
			),
			[
				_state,
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
						fcppt::parse::skipper::make_success<
							Ch
						>()
					:
						fcppt::parse::skipper::make_failure(
							fcppt::parse::detail::expected(
								_state.get().stream().get_position(),
								std::basic_string<
									Ch
								>{
									this->ch_
								},
								_ch
							)
						)
					;
			}
		);
}

#endif
