//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_SPACE_SET_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_SPACE_SET_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Ch
>
inline
std::unordered_set<
	Ch
>
space_set()
{
	return
		std::unordered_set<
			Ch
		>{
			FCPPT_CHAR_LITERAL(Ch, ' '),
			FCPPT_CHAR_LITERAL(Ch, '\n'),
			FCPPT_CHAR_LITERAL(Ch, '\t')
		};
}

}
}
}

#endif
