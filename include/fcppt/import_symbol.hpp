//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPORT_SYMBOL_HPP_INCLUDED
#define FCPPT_IMPORT_SYMBOL_HPP_INCLUDED

#if defined(_MSC_VER)
#	define FCPPT_IMPORT_SYMBOL_IMPL __declspec(dllimport)
#elif defined(__GNUC__)
#	define FCPPT_IMPORT_SYMBOL_IMPL
#else
#	error "Don't know what FCPPT_IMPORT_SYMBOL should be"
#endif

/// Tells that a symbol should be imported from a library
#define FCPPT_IMPORT_SYMBOL FCPPT_IMPORT_SYMBOL_IMPL

#endif
