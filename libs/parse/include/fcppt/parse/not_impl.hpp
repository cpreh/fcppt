//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_NOT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_NOT_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/not_decl.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::not_<
	Parser
>::not_(
	Parser &&_parser
)
:
	parser_{
		std::move(
			_parser
		)
	}
{
}

template<
	typename Parser
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	typename
	fcppt::parse::not_<
		Parser
	>::result_type
>
fcppt::parse::not_<
	Parser
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
	typename
	fcppt::parse::state<
		Ch
	>::pos_type pos{
		_state.get().stream().tellg()
	};

	bool const has_value{
		fcppt::parse::deref(
			this->parser_
		).parse(
			_state,
			_context
		).has_value()
	};

	// TODO: Do we have to do error handling in case pos == pos_type(-1)?
	_state.get().stream().seekg(
		pos
	);

	return
		fcppt::optional::make_if(
			!has_value,
			fcppt::const_(
				fcppt::unit{}
			)
		);
}

#endif
