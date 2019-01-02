//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_FLOAT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FLOAT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/float_decl.hpp>
#include <fcppt/parse/get.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/state_impl.hpp>


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
	> const &_context
) const
{
	fcppt::parse::run_skipper(
		_state,
		_context
	);

	return
		fcppt::parse::get<
			Type
		>(
			_state
		);
}

#endif
