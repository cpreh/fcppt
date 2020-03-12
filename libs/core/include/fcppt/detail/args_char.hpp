//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ARGS_CHAR_HPP_INCLUDED
#define FCPPT_DETAIL_ARGS_CHAR_HPP_INCLUDED

#include <fcppt/detail/main_wchar.hpp>


namespace fcppt
{
namespace detail
{

using
args_char
=
#if defined(FCPPT_DETAIL_MAIN_WCHAR)
wchar_t
#else
char
#endif
;

}
}

#endif
