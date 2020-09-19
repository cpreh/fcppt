//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BLANK_SET_HPP_INCLUDED
#define FCPPT_PARSE_BLANK_SET_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/parse/basic_char_set_container.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
inline
fcppt::parse::basic_char_set_container<
	Ch
>
blank_set()
{
	return
		fcppt::parse::basic_char_set_container<
			Ch
		>{
			FCPPT_CHAR_LITERAL(Ch, ' '),
			FCPPT_CHAR_LITERAL(Ch, '\t')
		};
}

}
}

#endif
