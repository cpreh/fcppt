//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_CONCRETE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_CONCRETE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/base_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/detail/concrete_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser,
	typename Ch,
	typename Skipper
>
fcppt::parse::detail::concrete<
	Parser,
	Ch,
	Skipper
>::concrete(
	Parser &&_parser
)
:
	base_type{},
	parser_{
		std::move(
			_parser
		)
	}
{
}

template<
	typename Parser,
	typename Ch,
	typename Skipper
>
fcppt::parse::detail::concrete<
	Parser,
	Ch,
	Skipper
>::~concrete()
{
}

template<
	typename Parser,
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::detail::concrete<
		Parser,
		Ch,
		Skipper
	>::result_type
>
fcppt::parse::detail::concrete<
	Parser,
	Ch,
	Skipper
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
		parser_.parse(
			_state,
			_context
		);
}

#endif
