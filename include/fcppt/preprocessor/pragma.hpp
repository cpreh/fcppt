//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_PRAGMA_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_PRAGMA_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

/// Pragma macro, the same as #pragma
/**
 * This can be used to wrap pragma inside other macros
*/
#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#define FCPPT_PP_PRAGMA(x) __pragma(x)
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#define FCPPT_PP_PRAGMA(x) _Pragma(#x)
#else
#error "Don't know what pragma should be!"
#endif

#endif
