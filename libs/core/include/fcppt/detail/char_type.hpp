//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_CHAR_TYPE_HPP_INCLUDED
#define FCPPT_DETAIL_CHAR_TYPE_HPP_INCLUDED

#include <fcppt/public_config.hpp>

namespace fcppt::detail
{
using char_type =
#if defined(FCPPT_NARROW_STRING)
    char
#else
    wchar_t
#endif
    ;

}

#endif
