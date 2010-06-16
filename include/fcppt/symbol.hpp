//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYMBOL_HPP_INCLUDED
#define FCPPT_SYMBOL_HPP_INCLUDED

#if defined(FCPPT_SYMBOL)
#error "FCPPT_SYMBOL already defined"
#endif

#if defined(_MSC_VER)
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
#elif defined(__GNUC__)
#	include <fcppt/export_symbol.hpp>
#	define FCPPT_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what FCPPT_SYMBOL should be"
#endif

#endif
