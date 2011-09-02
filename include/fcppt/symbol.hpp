//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYMBOL_HPP_INCLUDED
#define FCPPT_SYMBOL_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	if defined(fcppt_EXPORTS) && defined(FCPPT_DYN_LINK)
#		error "fcppt_EXPORTS and FCPPT_DYN_LINK defined"
#	endif
#	if defined(fcppt_EXPORTS)
#		include <fcppt/export_symbol.hpp>
#		define FCPPT_SYMBOL FCPPT_EXPORT_SYMBOL
#	elif defined(FCPPT_DYN_LINK)
#		include <fcppt/import_symbol.hpp>
#		define FCPPT_SYMBOL FCPPT_IMPORT_SYMBOL
#	else
#		define FCPPT_SYMBOL
#	endif
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/export_symbol.hpp>
#	define FCPPT_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what FCPPT_SYMBOL should be"
#endif

#endif
