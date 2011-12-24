//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPORT_SYMBOL_HPP_INCLUDED
#define FCPPT_IMPORT_SYMBOL_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_IMPORT_SYMBOL_IMPL __declspec(dllimport)
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	define FCPPT_IMPORT_SYMBOL_IMPL
#else
#	error "Don't know what FCPPT_IMPORT_SYMBOL should be"
#endif

/**
\brief Tells that a symbol should be imported

\ingroup fcpptexport

This macro marks a symbol to be imported, so it can be used from another
library.

\see \ref exports_library
*/
#define FCPPT_IMPORT_SYMBOL FCPPT_IMPORT_SYMBOL_IMPL

#endif
