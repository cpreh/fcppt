//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SET_POSITION_HPP_INCLUDED
#define FCPPT_PARSE_SET_POSITION_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/detail/check_bad.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
void
set_position(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::position<
		Ch
	> const _pos
)
{
	std::basic_istream<
		Ch
	> &stream{
		_state.get().stream()
	};

	fcppt::parse::detail::check_bad(
		stream
	);

	stream.clear();

	stream.seekg(
		_pos
	);

	if(
		stream.fail()
	)
		throw
			fcppt::parse::detail::exception<
				Ch
			>{
				FCPPT_STRING_LITERAL(
					Ch,
					"seekg() failed."
				)
			};
}

}
}

#endif
