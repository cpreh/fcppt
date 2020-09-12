//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MAKE_CHAR_LITERALS_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_CHAR_LITERALS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


#define FCPPT_DETAIL_MAKE_CHAR_LITERALS(\
	_literal\
)\
std::make_tuple(\
	_literal,\
	L ## _literal,\
	u ## _literal,\
	U ## _literal\
)

#endif