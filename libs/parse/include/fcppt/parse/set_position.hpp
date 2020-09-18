//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SET_POSITION_HPP_INCLUDED
#define FCPPT_PARSE_SET_POSITION_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_impl.hpp>
#include <fcppt/parse/position.hpp>


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
		fcppt::parse::basic_stream<
			Ch
		>
	> const _state,
	fcppt::parse::position<
		Ch
	> const _pos
)
{
	_state.get().set_position(
		_pos
	);
}

}
}

#endif
