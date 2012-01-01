//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_SYMBOL_HPP_INCLUDED
#define FCPPT_THREAD_SYMBOL_HPP_INCLUDED

#if defined(FCPPT_STATIC_LINK)
#	define FCPPT_THREAD_SYMBOL
#elif defined(fcppt_thread_EXPORTS)
#	include <fcppt/export_symbol.hpp>
#	define FCPPT_THREAD_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	include <fcppt/import_symbol.hpp>
#	define FCPPT_THREAD_SYMBOL FCPPT_IMPORT_SYMBOL
#endif

#endif
