//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYMBOL_IMPORT_H_INCLUDED
#define FCPPT_SYMBOL_IMPORT_H_INCLUDED

#include <fcppt/config/compiler.h>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_SYMBOL_IMPORT_IMPL __declspec(dllimport)
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	define FCPPT_SYMBOL_IMPORT_IMPL
#else
#	error "Don't know what FCPPT_SYMBOL_IMPORT should be"
#endif

/**
\brief Tells that a symbol should be imported

\ingroup fcpptexport

This macro marks a symbol to be imported, so it can be used from another
library.

\see \ref symbol_library
*/
#define FCPPT_SYMBOL_IMPORT FCPPT_SYMBOL_IMPORT_IMPL

#endif
