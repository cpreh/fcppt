//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/io/get.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/parse/basic_literal_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/state_impl.hpp>


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
	fcppt::parse::run_skipper(
		_state,
		_context
	);

	return
		fcppt::optional::bind(
			fcppt::io::get(
				_state.get().stream()
			),
			[
				this
			](
				Ch const _ch
			)
			{
				return
					fcppt::optional::make_if(
						_ch
						==
						this->ch_,
						fcppt::const_(
							fcppt::unit{}
						)
					);
			}
		);
}

#endif
