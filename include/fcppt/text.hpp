//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TEXT_HPP_INCLUDED
#define FCPPT_TEXT_HPP_INCLUDED

#include <fcppt/config.h>

#ifndef FCPPT_NARROW_STRING
#define FCPPT_TEXT(x) L ## x
#else
#define FCPPT_TEXT(x) x
#endif

#endif
