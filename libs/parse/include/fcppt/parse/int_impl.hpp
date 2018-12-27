//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_INT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_INT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/int_decl.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/detail/check_bad.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
fcppt::parse::int_<
	Type
>::int_()
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
	fcppt::parse::int_<
		Type
	>::result_type
>
fcppt::parse::int_<
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

	std::basic_istream<
		Ch
	> &stream{
		_state.get().stream()
	};

	fcppt::parse::detail::check_bad(
		stream
	);

	return
		fcppt::io::extract<
			Type
		>(
			stream
		);
}

#endif
