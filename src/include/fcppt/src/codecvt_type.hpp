//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_CODECVT_TYPE_HPP_INCLUDED
#define FCPPT_SRC_CODECVT_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

typedef std::codecvt<
	wchar_t,
	char,
	std::mbstate_t
> codecvt_type;

}


#endif
