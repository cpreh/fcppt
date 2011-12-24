//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXPORT_SYMBOL_HPP_INCLUDED
#define FCPPT_EXPORT_SYMBOL_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_EXPORT_SYMBOL_IMPL __declspec(dllexport)
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/config.hpp>
#	if defined(FCPPT_HAVE_GCC_VISIBILITY)
#		define FCPPT_EXPORT_SYMBOL_IMPL __attribute__ ((visibility("default")))
#	else
#		define FCPPT_EXPORT_SYMBOL_IMPL
#	endif
#else
#	error "Don't know what FCPPT_EXPORT_SYMBOL should be"
#endif

/**
\brief Tells that a symbol should be exported

\ingroup fcpptexport

This macro marks a symbol to be exported, so it can be used by other libraries
or programs.

\see \ref exports_library
*/
#define FCPPT_EXPORT_SYMBOL FCPPT_EXPORT_SYMBOL_IMPL

#endif
