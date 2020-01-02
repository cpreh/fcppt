//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYMBOL_EXPORT_H_INCLUDED
#define FCPPT_SYMBOL_EXPORT_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_SYMBOL_EXPORT_IMPL __declspec(dllexport)
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	define FCPPT_SYMBOL_EXPORT_IMPL __attribute__ ((visibility("default")))
#else
#	error "Don't know what FCPPT_SYMBOL_EXPORT should be"
#endif

/**
\brief Tells that a symbol should be exported

\ingroup fcpptexport

This macro marks a symbol to be exported, so it can be used by other libraries
or programs.

\see \ref symbol_library
*/
#define FCPPT_SYMBOL_EXPORT FCPPT_SYMBOL_EXPORT_IMPL

#endif
