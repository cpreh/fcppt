//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_FAIL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FAIL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/fail_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>


template<
	typename Result
>
fcppt::parse::fail<
	Result
>::fail()
{
}

template<
	typename Result
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	typename
	fcppt::parse::fail<
		Result
	>::result_type
>
fcppt::parse::fail<
	Result
>::parse(
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
		fcppt::parse::result<
			result_type
		>{};
}

#endif
