//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_GET_POSITION_HPP_INCLUDED
#define FCPPT_PARSE_GET_POSITION_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/state_impl.hpp>
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
	typedef
	fcppt::parse::position<
		Ch
	>
	pos_type;

	pos_type const pos{
		_state.get().stream().tellg()
	};

	if(
		pos
		==
		pos_type{
			-1
		}
	)
		throw
			fcppt::parse::detail::exception<
				Ch
			>{
				"tellg() failed."
			};

	return
		pos;
}

}
}

#endif
