//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_PRAGMA_H_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_PRAGMA_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#define FCPPT_PP_DETAIL_PRAGMA(x) __pragma(x)
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#define FCPPT_PP_DETAIL_PRAGMA(x) _Pragma(#x)
#else
#error "Don't know what pragma should be!"
#endif

#endif
