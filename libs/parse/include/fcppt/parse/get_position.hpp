//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_GET_POSITION_HPP_INCLUDED
#define FCPPT_PARSE_GET_POSITION_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/detail/check_bad.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
fcppt::parse::position<
	Ch
>
get_position(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state
)
{
	using
	pos_type
	=
	typename
	std::basic_istream<
		Ch
	>::pos_type;

	std::basic_istream<
		Ch
	> &stream{
		_state.get().stream()
	};

	fcppt::parse::detail::check_bad(
		stream
	);

	if(
		stream.eof()
	)
	{
		stream.clear(); // NOLINT(fuchsia-default-arguments-calls)
	}

	pos_type const pos{
		stream.tellg()
	};

	if(
		pos
		==
		pos_type{
			-1
		}
	)
	{
		throw
			// NOLINTNEXTLINE(hicpp-exception-baseclass)
			fcppt::parse::detail::exception<
				Ch
			>{
				FCPPT_STRING_LITERAL(
					Ch,
					"tellg() failed."
				)
			};
	}

	return
		std::make_pair(
			pos,
			// TODO
			fcppt::optional::object<
				fcppt::parse::line_number
			>{}
		);
}

}
}

#endif
