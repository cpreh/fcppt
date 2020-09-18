//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_GET_CHAR_HPP_INCLUDED
#define FCPPT_PARSE_GET_CHAR_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_stream_impl.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
fcppt::optional::object<
	Ch
>
get_char(
	fcppt::reference<
		fcppt::parse::basic_stream<
			Ch
		>
	> const _state
)
{
	return
		_state.get().get_char();
}

}
}

#endif
