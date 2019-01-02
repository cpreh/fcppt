//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_EPSILON_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_EPSILON_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/epsilon_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>


inline
fcppt::parse::epsilon::epsilon()
{
}

template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	fcppt::parse::epsilon::result_type
>
fcppt::parse::epsilon::parse(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	>,
	fcppt::parse::context<
		Skipper
	> const &
) const
{
	return
		fcppt::optional::make(
			fcppt::unit{}
		);
}

#endif
