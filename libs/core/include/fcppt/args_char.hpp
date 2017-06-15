//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ARGS_CHAR_HPP_INCLUDED
#define FCPPT_ARGS_CHAR_HPP_INCLUDED

#include <fcppt/detail/main_wchar.hpp>


namespace fcppt
{

/**
\brief The char type of the main function.

\ingroup fcpptvarious
*/
typedef
#if defined(FCPPT_DETAIL_MAIN_WCHAR)
wchar_t
#else
char
#endif
args_char;

}

#endif
