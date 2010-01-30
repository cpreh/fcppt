//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYMBOL_HPP_INCLUDED
#define FCPPT_SYMBOL_HPP_INCLUDED

#include <fcppt/export_symbol.hpp>

#if defined(_MSC_VER)
#	include <fcppt/import_symbol.hpp>
#	ifdef fcppt_EXPORTS
#		define FCPPT_SYMBOL FCPPT_EXPORT_SYMBOL
#	else
#		define FCPPT_SYMBOL FCPPT_IMPORT_SYMBOL
#	endif
#elif defined(__GNUC__)
#	define FCPPT_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what FCPPT_SYMBOL should be"
#endif


#endif
